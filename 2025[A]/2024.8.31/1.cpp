#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,x,y,n,i;
struct nod{
	int u,v,next;
};
nod a[200009];
int fir[100009],vis[100009],cnt,f=0,ans;
int leaves,inl,l1,l0;
char c[100009];
void add(int x,int y){
	cnt++;
	a[cnt].u=x;a[cnt].v=y;a[cnt].next=fir[x];
	fir[x]=cnt;
}
void dfs(int u){//op==1 Irics op==0 Dora
	int i;
	bool f=0;
	vis[u]=1;
	for(i=fir[u];i;i=a[i].next){
		int v=a[i].v;
		if(vis[v]==0){
			f=1;
			dfs(v);
		}
	}
	if(f==0){
		if(c[u]=='?')leaves++;
		else if(c[u]=='1')l1++;
		else l0++;
	}
	else{
		if(u!=1&&c[u]=='?')inl++;
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;f=0;inl=leaves=l1=l0=0;cnt=0;
		for(i=1;i<=n;i++)vis[i]=fir[i]=0;
		for(i=1;i<n;i++){
			scanf("%lld%lld",&x,&y);
			add(x,y);add(y,x);
		}
		getchar();
		for(i=1;i<=n;i++){
			c[i]=getchar();
		}
		dfs(1);
		//Dora要小 
		if(c[1]=='?'){
			if(l0==l1){
				int xianshou=inl%2;
				if(xianshou==1){//xianshou==1 dora先选 
					ans=l0;//dora
					bool Irics=0;
					while(leaves>0){
						if(Irics==0){
							ans++;
							leaves--;
							Irics=1;
						}
						else{
							leaves--;
							Irics=0;
						}
					}
				}
				else{//xianshou==0 Irics先选 
					ans=l0;//Irics
					bool Irics=1;
					while(leaves>0){
						if(Irics==0){
							ans++;
							leaves--;
							Irics=1;
						}
						else{
							leaves--;
							Irics=0;
						}
					}
				}
			}
			else{
				ans=max(l0,l1);//Irics
				leaves--;//dora
				bool Irics=0;
				while(leaves>0){
					if(Irics==0){
						ans++;
						leaves--;
						Irics=1;
					}
					else{
						leaves--;
						Irics=0;
					}
				}
			}
		}
		else{
			if(c[1]=='1'){
				ans=l0;
				ans+=(leaves+1)/2;
			}
			else{
				ans=l1;
				ans+=(leaves+1)/2;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
