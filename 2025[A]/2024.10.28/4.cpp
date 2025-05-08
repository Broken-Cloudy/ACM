#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,a[300009],l,r,q,sum[300009],poi[300009],x,y,Sum[300009],S[300009];
int ans,P[300009],jie[300009];
int getans(int n_th,int x){
	int l;
	int r;
	int kk=0;
	l=1;r=(n_th-1)+x;
	if(x==0)return 0LL;
	kk+=P[r];kk-=Sum[n_th-1]*(r-1);kk-=sum[r];
}
int check(int n_th,int l,int r){
	int ans=0;
	ans-=getans(n_th,l-1);
	ans+=getans(n_th,r);
	return ans;
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++){
		poi[i]=poi[i-1]+(n-i+1);
	}
	for(i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		P[i]=P[i-1]+sum[i];
		Sum[1]+=sum[i];
	}
	for(i=1;i<=n;i++){
		jie[i]=jie[i-1]+sum[i];
	}
	for(i=2;i<=n;i++){
		Sum[i]=Sum[i-1]-(a[i-1]*(n-i+2));
		S[i]=S[i-1]+Sum[i];
	}
	cin>>q;
	while(q--){
		scanf("%lld%lld",&l,&r);
		x=lower_bound(poi+1,poi+1+n,l)-poi;
		y=lower_bound(poi+1,poi+1+n,r)-poi;
		if(x==y){
			ans=check(x,l-poi[x-1],r-poi[x-1]);
		}
		else{
			ans=S[y-1]-S[x];
			ans+=check(y,1,r-poi[y-1]);
			ans+=check(x-1,l,poi[x]-1);
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
