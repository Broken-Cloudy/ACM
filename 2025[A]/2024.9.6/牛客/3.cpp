#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,a[200009],b[200009],i,ans;
bool f=0;
map<int,int>m;
signed main(){
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%lld",&b[i]);
		m[b[i]]++;
	}
	for(i=1;i<=n;i++){
		if(m[b[i]]==0)continue;
		else if(m[b[i]]==1){
			f=1;
			break;
		}
		else{
			ans+=(m[b[i]]+1)/2;
			m[b[i]]=0;
		}
	}
	if(f==1)cout<<"-1"<<endl;
	else cout<<ans<<endl;
	return 0;
}
