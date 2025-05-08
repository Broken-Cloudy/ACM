#include<bits/stdc++.h>
using namespace std;
int a[200009],i,k,n,ans,len,ANS=1000000009;
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		a[k]++;
	}
	for(len=1;len<=sqrt(200000)+5;len++){
		ans=len-1;i=1;
		while(i<=200005){
			if(a[i]>0){
				i+=len;
				ans++;
			}
			else i++;
		}
		ANS=min(ans,ANS);
	}
	printf("%lld\n",ANS);
	fclose(stdin);fclose(stdout);
	return 0;
}
