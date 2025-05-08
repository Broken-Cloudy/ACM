#include<bits/stdc++.h>
#define int long long
using namespace std;
int power[109],i,j,n,k;
int gelei[1009];
signed main(){
	freopen("B.in","r",stdin);freopen("B.out","w",stdout);
	power[0]=1;
	for(i=1;i<=61;i++)power[i]=power[i-1]*2;
	cin>>n;
	gelei[0]=0;
	while(k<n){
		for(i=power[k]+1,j=power[k];i<=power[k+1]&&j>=1;i++,j--){
			gelei[i]=gelei[j]+power[k];
		}
		k++;
	}
	for(i=1;i<=power[n];i++){//ÐÐ 
		for(j=1;j<=power[n];j++){//ÁÐ 
			if(j==power[n])printf("%lld\n",gelei[j]+power[n]*gelei[i]);
			else printf("%lld ",gelei[j]+power[n]*gelei[i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
