#include<bits/stdc++.h>
#define int long long
using namespace std;
int prime[800009],cnt,flag[800009],NUM[800009];
const int inf=10000000000000009LL;
int T,j,i,n,a[100009],zhi;
int fir[100009];
bool ff;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	for(i=1;i<=100000;i++)fir[i]=inf;
	flag[1]=1;
	for(i=2;i<=800000;i++){
		if(flag[i]==0){
			prime[++cnt]=i;//记录下来 
			NUM[i]=cnt;
		}
		for(j=1;j<=cnt&&i*prime[j]<=800000;j++){
			flag[prime[j]*i]=prime[j];//一下子筛到底 
			//当然，i肯定比prime[j]大，因为prime[j]是在i之前得出的
			if(i%prime[j]==0)break;
		}
	}
	cin>>T;
	while(T--){
		scanf("%lld",&n);zhi=0;ff=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(i=1;i<=n;i++){
			if(flag[a[i]]==0){
				if(zhi>0&&zhi!=a[i]){
					ff=1;
					break;
				}
				else{
					zhi=a[i];
				}
			}
		}
		if(zhi==0){
			printf("2\n");
			continue;
		}
		if(ff==1){
			printf("-1\n");
			continue;
		}
		for(i=1;prime[i]<=sqrt(400000);i++){
			fir[i]=min(fir[i],zhi*prime[i]);
			for(j=i+1;prime[j]<=sqrt(400000);j++){
				fir[j]=min(fir[j],(fir[i]+prime[j]*prime[i]-1)/(prime[j]*prime[i])*(prime[j]*prime[i]));
			}
		}
		for(i=1;i<=n;i++){
			if(flag[a[i]]>0){
				if(a[i]<zhi||a[i]>zhi&&a[i]<2*zhi){
					ff=1;
					break;
				}
				if(fir[NUM[flag[a[i]]]]==inf){
					continue;
				}
				if(fir[NUM[flag[a[i]]]]>a[i]){
					ff=1;
					break;
				}
			}
		}
		if(ff==1)printf("-1\n");
		else printf("%lld\n",zhi);
		for(i=1;prime[i]<=sqrt(zhi);i++){
			fir[i]=inf;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
