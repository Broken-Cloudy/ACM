#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int x,y;
}a[100009];
int n,i,k,b,UP,DOWN,ANS;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].x,&a[i].y);
	}
	scanf("%lld%lld",&k,&b);
	if(k==0&&b==0){
		for(i=1;i<=n;i++){
			if(a[i].x>0){
				UP++;
			}
			else DOWN++;
		}
		ANS=min(UP,DOWN);
	}
	else if(k==0){
		for(i=1;i<=n;i++){
			if(a[i].y>b){
				UP++;
			}
			else DOWN++;
		}
		ANS=min(UP,DOWN);
	}
	else{
		for(i=1;i<=n;i++){
			if(a[i].y>a[i].x*k+b){
				UP++;
			}
			else DOWN++;
		}
		ANS=min(UP,DOWN);
	}
	printf("%lld\n",ANS);
	fclose(stdin);fclose(stdout);
	return 0;
}
