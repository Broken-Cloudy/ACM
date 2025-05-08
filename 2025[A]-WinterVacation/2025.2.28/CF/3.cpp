#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
}a[200009];
int fir[100009],cnt;
int T,n,j,i,st,en,x,y;
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&st,&en);
		cnt=0;for(i=1;i<=n;i++)fir[i]=0;
		for(i=1;i<n;i++){
			scanf("%lld%lld",&x,&y);
			add(x,y);add(y,x);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
