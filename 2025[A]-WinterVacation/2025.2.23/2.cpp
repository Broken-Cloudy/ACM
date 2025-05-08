#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,j,k,a[100009],T,ANS,f[100009],ans[200009],kk;
queue<int>q;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ANS=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i+=2)ANS+=(n-i+1);
		for(k=1;k<=10;k++){
			for(i=1;i<=n;i++){
				if(a[i]>k)f[i]=1;
				else if(a[i]==k)f[i]=0;
				else f[i]=-1;
			}
			kk=n;for(i=0;i<=2*n;i++)ans[i]=0;
			for(i=2;i<=n;i+=2){
				if(f[i]==0||f[i-1]==0){
					if(f[i]==1||f[i-1]==1){
						ANS+=ans[kk];kk-=1;ans[kk+1]+=1;ANS+=ans[kk];
					}
					else if(f[i]==-1||f[i-1]==-1){
						ANS+=ans[kk];kk+=1;ans[kk-1]+=1;ANS+=ans[kk];
					}
					else{
						kk+=0;ans[kk]+=1;ANS+=ans[kk];
					}
				}
				else{
					if(f[i]==1&&f[i-1]==1){
						kk-=2;ANS+=ans[kk];
					}
					else if(f[i]==-1&&f[i-1]==-1){
						kk+=2;ANS+=ans[kk];
					}
					else{
						kk+=0;ANS+=ans[kk];
					}
				}
			}
			kk=n;for(i=0;i<=2*n;i++)ans[i]=0;
			for(i=3;i<=n;i+=2){
				if(f[i]==0||f[i-1]==0){
					if(f[i]==1||f[i-1]==1){
						ANS+=ans[kk];kk-=1;ans[kk+1]+=1;ANS+=ans[kk];
					}
					else if(f[i]==-1||f[i-1]==-1){
						ANS+=ans[kk];kk+=1;ans[kk-1]+=1;ANS+=ans[kk];
					}
					else{
						kk+=0;ans[kk]+=1;ANS+=ans[kk];
					}
				}
				else{
					if(f[i]==1&&f[i-1]==1){
						kk-=2;ANS+=ans[kk];
					}
					else if(f[i]==-1&&f[i-1]==-1){
						kk+=2;ANS+=ans[kk];
					}
					else{
						kk+=0;ANS+=ans[kk];
					}
				}
			}
		}
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
