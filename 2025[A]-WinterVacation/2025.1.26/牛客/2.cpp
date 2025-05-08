#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,i,acnt,bcnt,v;
double a[100009],b[100009],ANS,pi,u,poi[100009];
int check(double times){
	int i,j,d1,d2,ans=0;
	for(i=1;i<=acnt;i++){
		d1=poi[i];
		d2=upper_bound(b+1,b+1+bcnt,a[i]+2.0*times)-b;
		ans+=(d2-d1);
	}
	return ans;
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		scanf("%lf%lld",&u,&v);
		if(v==1){
			a[++acnt]=u;
		}
		else{
			b[++bcnt]=u;
		}
	}
	sort(a+1,a+1+acnt);sort(b+1,b+1+bcnt);
	for(i=1;i<=acnt;i++){
		poi[i]=upper_bound(b+1,b+1+bcnt,a[i])-b;
	}
	if(check(1000000000)<k){
		printf("No\n");
	}
	else{
		printf("Yes\n");
		for(i=1;i<=29;i++){
			pi=0.5;
			while(check(ANS+pi)<k){
				pi*=2.0;
			}
			if(pi==0.5)break;
			else pi/=2.0;
			ANS+=pi;
		}
		ANS+=0.5;
		printf("%.6lf\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
