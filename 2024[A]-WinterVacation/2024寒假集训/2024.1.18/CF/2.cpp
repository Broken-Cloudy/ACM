#include<iostream>
#include<cstdio>
using namespace std;
int n,T,i,k,a[300009],sum[300009];
long long C2[300009],C3[300009];
long long ans;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(i=2;i<=300000;i++){
		C2[i]=1;
		C2[i]*=i;
		C2[i]*=(i-1);
		C2[i]/=2;
	}
	for(i=3;i<=300000;i++){
		C3[i]=1;
		C3[i]*=i;
		C3[i]*=(i-1);
		C3[i]*=(i-2);
		C3[i]/=6;
	}
	for(int o=1;o<=T;o++){
		cin>>n;ans=0;
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			a[k]++;
		}
		for(i=0;i<=n;i++){
			sum[i]=sum[i-1]+a[i-1];
		}
		for(i=0;i<=n;i++){
			if(a[i]==2){
				long long t=C2[2];
				t*=sum[i];
				ans+=t;
			}
			else if(a[i]>=3){
				long long t=C2[a[i]];
				t*=sum[i];
				ans+=C3[a[i]];
				ans+=t;
			}
		}
		printf("%lld\n",ans);
		for(i=0;i<=n;i++)a[i]=sum[i]=0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
