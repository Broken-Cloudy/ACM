#include<bits/stdc++.h>
using namespace std;
long long n,t,ans,k,a;
int main(){
	freopen("9.in","r",stdin);freopen("9.out","w",stdout);
	cin>>t>>a>>k;
	if(t==0){
		ans=2*max(a,-a);
		cout<<ans<<endl;
	}
	else if(a==0){
		ans=max(t,-t);
		cout<<ans<<endl;
	}
	else{
		if(a*t>0){//同向 
			if(max(t,-t)>=max(a,-a)){
				cout<<max(t,-t)<<endl;
			}
			else{
                ans+=max(t,-t);
                ans+=2*(max(a,-a)-max(t,-t));
				cout<<ans<<endl;
			}
		}
		else{
			if(a>=-k&&a<=k){//看得见 
				ans+=2*max(a,-a);
				ans+=max(t,-t);
				cout<<ans<<endl;
			}
			else{
				ans+=max(t,-t);
				ans+=2*max(a,-a);
				ans+=2*max(t,-t);
				cout<<ans<<endl;
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
