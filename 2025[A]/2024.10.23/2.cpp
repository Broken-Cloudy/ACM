#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,m,q,p[100009],b[100009],fir[100009],x,y,z,cnt;
struct nod{
	int u,v,w,next;
}a[200009];
void add(int x,int y,int z){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;a[cnt].w=z;
	fir[x]=cnt;
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>m>>q;
	for(i=1;i<=n;i++){
		scanf("%lld",&p[i]);
	}
	for(i=1;i<=m;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);add(y,x,z);
	}
	for(i=1;i<=m;i++){
		scanf("%lld",&b[i]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
