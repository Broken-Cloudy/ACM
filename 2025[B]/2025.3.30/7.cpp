#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
}a[50009];
queue<int>q;
bool ff,F;
int N,M,i,fir[509],x,y,cnt,A,B,f[509];
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
signed main(){
	freopen("7.in","r",stdin);freopen("7.out","w",stdout);
	cin>>N>>M;
	for(i=1;i<=M;i++){
		scanf("%lld%lld",&x,&y);
		add(x,y);
	}
	cin>>A>>B;
	q.push(A);f[A]=1;F=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		ff=0;
		for(i=fir[u];i;i=a[i].next){
			int v=a[i].v;
			ff=1;
			f[v]+=f[u];
			q.push(v);
		}
		if(u!=B)f[u]=0;
		if(ff==0&&u!=B)F=0;
	}
	if(F==1)cout<<f[B]<<' '<<"Yes"<<endl;
	else cout<<f[B]<<' '<<"No"<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
