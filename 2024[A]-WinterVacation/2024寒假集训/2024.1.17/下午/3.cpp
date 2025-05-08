#include<bits/stdc++.h>
using namespace std;
int T,n,a[200009],i,prime[200009],cnt=2,j,k,ans,b[200009];
int number1,number2;
bool flag=0,fff,ff,f;
int main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout); 
	cin>>T;
	prime[1]=1;prime[2]=2;
	for(i=3;i<=200000;i++){//prime 
		flag=0;
		for(j=2;j*j<=i;j++){
			if(i%j==0){
				flag=1;
				break;
			}
		}
		if(flag==1)continue;
		else{
			prime[++cnt]=i;
		}
	}
	for(int o=1;o<=T;o++){
		ans=0;f=0;b[0]=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=2;i<=cnt;i++){//1
			if(prime[i]>n)break;
			for(j=1;j<n;j++){
				if(a[j+1]%prime[i]!=a[j]%prime[i]){
					break;
				}
			}
			if(j==n){
				ans++;
				break;
			}
			f=1;
		}
		ans++;//max
		for(int r=2;r*r<=n;r++){//分组 
			ff=0;
			if(n%r!=0)continue;
			else{
				if(r*r!=n)b[++b[0]]=n/r;
			}
			for(i=2;i<=cnt;i++){//除以数字 
				if(prime[i]>n)break;
				if(ff==1)break;
				k=0;
				while(k<=r-1){
					for(j=1+k+r;j<=n;j+=r){
						if(a[j-r]%prime[i]!=a[j]%prime[i]){
							fff=1;
							break;
						}
					}
					if(fff==1){
						fff=0;
						break;
					}
					else if(fff==0&&k==min(r-1,3)){
						ans++;
						fff=0;
						ff=1;
						break;
					}
					else if(fff==0&&k!=r-1){
						k++;
					}
				}
			}
		}
		for(int tt=1;tt<=b[0];tt++){//分组 
			ff=0;
			int r=b[tt];
			for(i=2;i<=cnt;i++){//除以数字 
				if(prime[i]>n)break;
				if(ff==1)break;
				k=0;
				while(k<=r-1){
					for(j=1+k+r;j<=n;j+=r){
						if(a[j-r]%prime[i]!=a[j]%prime[i]){
							fff=1;
							break;
						}
					}
					if(fff==1){
						fff=0;
						break;
					}
					else if(fff==0&&k==min(r-1,3)){
						ans++;
						fff=0;
						ff=1;
						break;
					}
					else if(fff==0&&k!=r-1){
						k++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
