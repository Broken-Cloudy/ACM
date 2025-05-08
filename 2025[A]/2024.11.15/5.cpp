#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
}a[2000009];
int cnt,fir[1000009];
int T,i,n,p;
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
		scanf("%lld",&n);cnt=0;
		for(i=1;i<=n;i++)fir[i]=0;
		for(i=2;i<=n;i++){
			scanf("%lld",&p);
			add(i,p);add(p,i);
		}
		
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
