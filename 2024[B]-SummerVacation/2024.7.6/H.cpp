#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c,ans,pow3[32],i;
signed main(){
	freopen("H.in","r",stdin);freopen("H.out","w",stdout);
	cin>>a>>b>>c;
	pow3[0]=1;
	for(i=1;i<=27;i++){
		pow3[i]=pow3[i-1]*3;
	}
	ans=b*pow3[a+2];
	if(c==0){
		ans*=4;
		if(ans%100==0)ans=ans;
		else{
			ans+=100;
			ans-=(ans%100);
		}
		cout<<ans<<endl;
	}
	else{
		if(ans%100==0)ans=ans;
		else{
			ans+=100;
			ans-=(ans%100);
		}
		ans*=3;
		cout<<ans<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
