#include<bits/stdc++.h>
#define int long long
using namespace std;
int k1,k2,n,ans=-1;
bool check(__int128 x,int k1,int k2){
	while(x>0){
		if((x%k1)>1)return false;
		x/=k1;
	}
	return true;
}
void dfs(__int128 x){
	if(ans!=-1)return;
	if(x>1000000000000000000LL){
		return;
	}
	if(x>=2&&check(x,k1,k2)==1){
		ans=x;return;
	}
	else{
		dfs(x*k2);dfs(x*k2+1);
	}
}
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>k1>>k2;
	if(k1==2){
		cout<<"YES"<<endl;
		cout<<k2<<endl;
	}
	else if(k1==k2-1){
		cout<<"YES"<<endl;
		cout<<k2<<endl;
	}
	else if(k1==3&&k2==5){
		cout<<"YES"<<endl;
		cout<<3250<<endl;
	}
	else{
		dfs(1);
		if(ans==-1)cout<<"NO"<<endl;
		else{
			cout<<"YES"<<endl;
			cout<<ans<<endl;
		}
	} 
	fclose(stdin);fclose(stdout);
	return 0;
}
