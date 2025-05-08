#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,a[200009],b[200009],p,l,r,j;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		l=1;r=n;
		for(i=1;i<=20;i++){
			if(i%2==1){//Ïû³ý´ó 
				for(j=1;j<=n;j++){
					if(a[j]==i){
						b[j]=r;
						r--;
					}
					if(a[j]==-1)break;
				}
				for(j=n;j>=1;j--){
					if(a[j]==i){
						b[j]=r;
						r--;
					}
					if(a[j]==-1)break;
				}
			}
			else{
				for(j=1;j<=n;j++){
					if(a[j]==i){
						b[j]=l;
						l++;
					}
					if(a[j]==-1)break;
				}
				for(j=n;j>=1;j--){
					if(a[j]==i){
						b[j]=l;
						l++;
					}
					if(a[j]==-1)break;
				}
			}
		}
		for(i=1;i<=n;i++)if(a[i]==-1)b[i]=l;
		for(i=1;i<=n;i++){
			if(i==n)printf("%lld\n",b[i]);
			else printf("%lld ",b[i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
