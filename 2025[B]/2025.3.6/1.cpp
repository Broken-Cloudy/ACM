#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,p10[12],ANS,k,r,j,kk;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;p10[0]=1;
	for(i=1;i<=10;i++)p10[i]=p10[i-1]*10;
	while(T--){
		scanf("%lld",&n);
		k=n%10;if(k<7)k+=10;k-=7;ANS=k;
		for(i=9;i>=1;i--){
			k=n/p10[i]%10;r=n%p10[i];
			if(k>7)k-=10;k=7-k;
			if(r<k)k++;
			ANS=min(ANS,k);
			kk=-1;k=0;
			while(r>0&&kk==-1){
				for(j=0;j<=9;j++){
					if(r/p10[j]%10==7){
						kk=k;
						break;
					}
				}
				r--;k++;
			}
			if(kk!=-1)ANS=min(ANS,kk);
		}
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
