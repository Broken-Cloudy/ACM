#include<bits/stdc++.h>
#define int long long
using namespace std;
int N,i,k,j,bh,S[10009],cnt,mini,anss;
double taoshu[10009],SS[10009],numb,x,y;
struct nod{
	int k;
	int fa,mo;
	int child[8];
}a[10009];
set<int>adj[10009];
struct node{
	int bh;
	int num;
	double tao,S;
}ans[10009];
bool cmp(node x,node y){
	if(x.S==y.S)return x.bh<y.bh;
	else return x.S>y.S;
}
void add(int x,int bh){
	if(S[x]>0&&S[x]!=S[bh]){
		int BH=S[x];
		for(auto t:adj[BH]){
			adj[S[bh]].insert(t);
			S[t]=S[bh];
		}
		taoshu[S[bh]]+=taoshu[BH];
		SS[S[bh]]+=SS[BH];
	}
	else{
		adj[S[bh]].insert(x);
		S[x]=S[bh];
	}
}
void putout(int x){
	if(x>=1000)printf("%lld ",x);
	else if(x>=100)printf("0%lld ",x);
	else if(x>=10)printf("00%lld ",x);
	else printf("000%lld ",x);
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>N;
	for(i=1;i<=N;i++){
		scanf("%lld",&bh);
		scanf("%lld%lld%lld",&a[bh].fa,&a[bh].mo,&a[bh].k);
		for(j=1;j<=a[bh].k;j++)scanf("%lld",&a[bh].child[j]);
		if(S[bh]==0){
			cnt++;
			S[bh]=cnt;
		}
		adj[S[bh]].insert(bh);
		for(j=1;j<=a[bh].k;j++)add(a[bh].child[j],bh);
		if(a[bh].fa>0)add(a[bh].fa,bh);
		if(a[bh].mo>0)add(a[bh].mo,bh);
		scanf("%lf%lf",&x,&y);
		taoshu[S[bh]]+=x;SS[S[bh]]+=y;
	}
	for(i=0;i<=10000;i++){
		if(S[i]!=0){
			numb=0;mini=i;
			int BH=S[i];
			for(auto t:adj[BH]){
				numb+=1;
				S[t]=0;
				mini=min(mini,t);
			}
			anss++;
			ans[anss].bh=mini;
			ans[anss].num=numb;
			ans[anss].tao=taoshu[BH]/numb;
			ans[anss].S=SS[BH]/numb;
		}
	}
	sort(ans+1,ans+1+anss,cmp);
	printf("%lld\n",anss);
	for(i=1;i<=anss;i++){
		putout(ans[i].bh);
		printf("%lld %.3lf %.3lf\n",ans[i].num,ans[i].tao,ans[i].S);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
