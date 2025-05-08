#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
}a[400009];
int T,n,s,i,x,y,cnt,fir[200009];
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];
	a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&s);
		for(i=1;i<=n;i++){
			scanf("%lld",&x);
			add(i,x);add(x,i);
		}
		for(i=1;i<=n;i++)fir[i]=0;cnt=0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
