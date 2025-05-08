#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,Q,t,ANS,a[300009],b[300009],S[300009],SS[300009],l,r,x,y,poi[300009];
int getnums(int deep,int x){
	int i=x+(deep-1);//3
	int ans=S[i]-S[deep-1];
	ans-=b[deep-1]*x;//x表示在当前数位排名多少 
	return ans;
}
int getlr(int deep,int l,int r){
	int L=getnums(deep,l-1);
	int R=getnums(deep,r);
	int ansl=getnums(deep,l-1);
	int ansr=getnums(deep,r);
	return (ansr-ansl);
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(i=1;i<=n;i++){
		S[i]=S[i-1]+b[i];
	}
	for(i=1;i<=n;i++){
		SS[i]=SS[i-1]+getnums(i,n-i+1);//1th--n_th
	}
	for(i=1;i<=n;i++){
		t=n-i+1;
		poi[i]=poi[i-1]+t;
	}
	cin>>Q;
	while(Q--){
		scanf("%lld%lld",&l,&r);
		x=lower_bound(poi+1,poi+1+n,l)-poi; 
		y=lower_bound(poi+1,poi+1+n,r)-poi;
		if(x==y){
			ANS=getlr(x,l-poi[x-1],r-poi[y-1]);
		}
		else{
			ANS=SS[y-1]-SS[x];
			ANS+=getlr(x,l-poi[x-1],n-x+1);
			ANS+=getlr(y,1,r-poi[y-1]);
		}
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
