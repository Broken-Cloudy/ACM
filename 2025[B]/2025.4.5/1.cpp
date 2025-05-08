#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=998244353LL;
struct nod{
	int n,m,C;
}f[8888],g[8888];
int T,a[16],b[16],i,j,SUM,n,m,x,y,k[16],fcnt,gcnt,t,ans,ANS;
int nifac[250009],fac[250009];
bool cmp(nod x,nod y){
	return x.m<y.m;
}
void exgcd(int a,int b){
	if(b==0){
		x=1;y=0;
		return;
	}
	exgcd(b,a%b);
	int t=x;
	x=y;y=t-(a/b)*y;
}
int C(int x,int y){
	if(x<y)return 0LL;
	int ans=fac[x];
	ans*=nifac[y];ans%=P;
	ans*=nifac[x-y];ans%=P;
	return ans;
}
void dfs(int depth){//8192
	if(depth==a[0]+1){
		fcnt++;f[fcnt].m=f[fcnt].n=0;f[fcnt].C=1;
		for(int i=1;i<=a[0];i++){//13
			if(f[fcnt].C==0)break;
			if(k[i]==0){
				f[fcnt].C*=C(n-f[fcnt].n,a[i]);
				f[fcnt].C%=P;
				f[fcnt].n+=a[i];
			}
			else{
				f[fcnt].C*=C(m-f[fcnt].m,a[i]);
				f[fcnt].C%=P;
				f[fcnt].m+=a[i];//选给奇数 
			}
		}
		return;
	}
	k[depth]=0;dfs(depth+1);
	k[depth]=1;dfs(depth+1);
}
void DFS(int depth){
	if(depth==b[0]+1){
		gcnt++;g[gcnt].m=g[gcnt].n=0;g[gcnt].C=1;
		for(int i=1;i<=b[0];i++){
			if(g[gcnt].C==0)break;
			if(k[i]==0){
				g[gcnt].n+=b[i];
				if(g[gcnt].n>n||g[gcnt].m>m){
					g[gcnt].C=0;break;
				}
				g[gcnt].C*=C(g[gcnt].n,b[i]);
				g[gcnt].C%=P;
			}
			else{
				g[gcnt].m+=b[i];
				if(g[gcnt].n>n||g[gcnt].m>m){
					g[gcnt].C=0;break;
				}
				g[gcnt].C*=C(g[gcnt].m,b[i]);
				g[gcnt].C%=P;
			}
		}
		return;
	}
	k[depth]=0;DFS(depth+1);
	k[depth]=1;DFS(depth+1);
}
void erfen(int L,int R,int x){
	if(L==R){
		if(x==g[L].m)ans=g[L].C;
		else ans=-1;
	}
	else if(L+1==R){
		if(x==g[L].m)ans=g[L].C;
		else if(x==g[R].m)ans=g[R].C;
		else ans=-1;
	}
	else{
		int MID=(L+R)/2;
		if(x>=g[MID].m)erfen(MID,R,x);
		else erfen(L,MID,x);
	}
	return;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	nifac[0]=fac[0]=1;
	for(i=1;i<=250009;i++){
		fac[i]=fac[i-1]*i;
		fac[i]%=P;
		exgcd(fac[i],P);
		nifac[i]=(x%P+P)%P;
	}
	cin>>T;
	while(T--){
		SUM=0;fcnt=gcnt=0;a[0]=b[0]=0;
		for(i=1;i<=13;i++){
			scanf("%lld",&t);
			if(t){
				a[++a[0]]=t;
				SUM+=a[a[0]];
			}
		}
		for(i=1;i<=13;i++){
			scanf("%lld",&t);
			if(t){
				b[++b[0]]=t;
				SUM+=b[b[0]];
			}
		}
		n=SUM/2;//偶数位 
		m=(SUM+1)/2;
		for(i=1;i<=a[0];i++)k[i]=0;dfs(1);
		for(i=1;i<=b[0];i++)k[i]=0;DFS(1);
		sort(f+1,f+1+fcnt,cmp);
		for(i=1;i<(1LL<<a[0]);i++){
			if(f[i].m==f[i+1].m){
				f[i+1].C+=f[i].C;
				f[i+1].C%=P;
				f[i].m=P;
				fcnt--;
			}
			else if(f[i].C==0){
				f[i].m=P;
				fcnt--;
			}
		}
		sort(f+1,f+1+(1LL<<a[0]),cmp);
		sort(g+1,g+1+gcnt,cmp);
		for(i=1;i<(1LL<<b[0]);i++){
			if(g[i].m==g[i+1].m){
				g[i+1].C+=g[i].C;
				g[i+1].C%=P;
				g[i].m=P;
				gcnt--;
			}
			else if(g[i].C==0){
				g[i].m=P;
				gcnt--;
			}
		}
		sort(g+1,g+1+(1LL<<b[0]),cmp);
		ANS=0;
		for(i=1;i<=fcnt;i++){
			t=f[i].m;
			erfen(1,gcnt,m-t);
			if(ans>=0){
				ANS+=(ans*f[i].C)%P;
				ANS%=P;
			}
		}
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
