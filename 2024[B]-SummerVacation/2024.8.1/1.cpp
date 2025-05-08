#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,len,next;
};
nod a[800009];
int T,n,u,v,len,fir[200009],i,j,cnt,vis[200009];
double ANS;
void add(int x,int y,int len){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;a[cnt].len=len;
	fir[x]=cnt;
}
double dfs(int x,double c0,double c1,bool turn){
	int i;
	double p,maxx=0,minn=1,ans;
	bool f=0;
	vis[x]=1;
	if(x!=1){
		p=c1/(c0+c1);//G可以吃到的
	}
	else p=1;
	for(i=fir[x];i;i=a[i].next){
		int y=a[i].v;
		if(vis[y]==0){
			f=1;
			if(a[i].len==1){
				ans=dfs(y,c0,c1+1,!turn);
				maxx=max(maxx,ans);
				minn=min(minn,ans);
			}
			else{
				ans=dfs(y,c0+1,c1,!turn);
				maxx=max(maxx,ans);
				minn=min(minn,ans);
			}
		}
	}
	if(f==0)return p;
	if(turn==1){
		p=min(p,maxx);
	}
	else{
		p=min(p,minn);
	}
	return p;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);cnt=0;
		for(i=0;i<=n;i++)fir[i]=0,vis[i]=0;
		for(i=1;i<n;i++){
			scanf("%lld%lld%lld",&u,&v,&len);
			add(u,v,len);add(v,u,len);
		}
		ANS=dfs(1,0,0,true);
		printf("%.9lf\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
