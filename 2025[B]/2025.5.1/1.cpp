#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int T,n,m,q,op,l,r,x,y,a[100009],i,ans,tree[800009],K[59];
void build(int node,int start,int end,int y){
	if(start==end){
		tree[i]=a[start]%y;
	}
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		build(zuo,start,mid,y);
		build(you,mid+1,end,y);
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>q>>m;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	while(q--){
		scanf("%lld%lld%lld",&op,&l,&r);
		if(op==1){
			scanf("%lld",&x);
			for(i=1;i<=m;i++){
				K[i]+=(x%i);
				K[i]%=i;//²éÑ¯Êý×Ö
			}
		}
		else{
			scanf("%lld",&y);
			//ans=sum(1,1,n,l,r,y);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
