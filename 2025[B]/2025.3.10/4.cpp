#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,a[109],b[109],f[109],ans1,ans2,ANS,p1,p2;
char A[109],B[109];
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++){
			getchar();
			scanf("%c %lld %c %lld",&A[i],&a[i],&B[i],&b[i]);
		}
		f[n+1]=3;
		for(i=n;i>=1;i--){
			if(A[i]=='x'&&B[i]=='x'){
				if(a[i]==3&&b[i]==3){
					f[i]=f[i+1];
				}
				else if(a[i]==3){
					f[i]=1;
				}
				else if(b[i]==3){
					f[i]=2;
				}
				else{
					f[i]=f[i+1];
				}
			}
			else if(A[i]=='x'){
				f[i]=1;
			}
			else if(B[i]=='x'){
				f[i]=2;
			}
			else f[i]=f[i+1];
		}
		ans1=ans2=1;
		for(i=1;i<=n;i++){
			if(f[i+1]==1){
				if(A[i]=='x')p1=ans1*(a[i]-1);
				else p1=a[i];
				if(B[i]=='x')p2=ans2*(b[i]-1);
				else p2=b[i];
				ans1+=(p1+p2);
			}
			else if(f[i+1]==2){
				if(A[i]=='x')p1=ans1*(a[i]-1);
				else p1=a[i];
				if(B[i]=='x')p2=ans2*(b[i]-1);
				else p2=b[i];
				ans2+=(p1+p2);
			}
			else{
				if(A[i]=='x')p1=ans1*(a[i]-1);
				else p1=a[i];
				if(B[i]=='x')p2=ans2*(b[i]-1);
				else p2=b[i];
				ans1+=(p1+p2);
			}
		}
		ANS=ans1+ans2;
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
