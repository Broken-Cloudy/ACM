#include<bits/stdc++.h>
using namespace std;
int N,i,k,j,bh,S[10009],cnt,x,y,mini,anss;
double taoshu[10009],SS[10009],numb;
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
	return x.S>y.S;
}
signed main(){
	freopen("L2-3.in","r",stdin);freopen("L2-3.out","w",stdout);
	cin>>N;
	for(i=1;i<=N;i++){
		scanf("%d",&bh);
		scanf("%d%d%d",&a[bh].fa,&a[bh].mo,&a[bh].k);
		for(j=1;j<=a[bh].k;j++){
			scanf("%d",&a[bh].child[j]);
		}
		if(S[a[bh].fa]>0)S[bh]=S[a[bh].fa];
		if(S[a[bh].mo]>0)S[bh]=S[a[bh].mo];
		for(j=1;j<=a[bh].k;j++)if(S[a[bh].child[j]]>0)S[bh]=S[a[bh].child[j]];
		if(S[bh]==0){
			cnt++;
			S[bh]=cnt;
		}
		for(j=1;j<=a[bh].k;j++){
			adj[S[bh]].insert(a[bh].child[j]);
			S[a[bh].child[j]]=S[bh];
		}
		adj[S[bh]].insert(bh);
		if(a[bh].fa>0)adj[S[bh]].insert(a[bh].fa),S[a[bh].fa]=S[bh];
		if(a[bh].mo>0)adj[S[bh]].insert(a[bh].mo),S[a[bh].mo]=S[bh];
		scanf("%d%d",&x,&y);
		taoshu[S[bh]]+=x;SS[S[bh]]+=y;
	}
	for(i=0;i<=10000;i++){
		if(S[i]!=0){
			numb=0;mini=i;
			for(auto t:adj[S[bh]]){
				numb+=1;
				S[t]=0;
				mini=min(mini,t);
			}
			anss++;
			ans[anss].bh=mini;
			ans[anss].num=numb;
			ans[anss].tao=taoshu[S[bh]]/numb;
			ans[anss].S=SS[S[bh]]/numb;
		}
	}
	sort(ans+1,ans+1+anss,cmp);
	printf("%lld\n",anss);
	for(i=1;i<=anss;i++){
		printf("%d %d %3.lf %3.lf\n",ans[i].bh,ans[i].num,ans[i].tao,ans[i].S);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
