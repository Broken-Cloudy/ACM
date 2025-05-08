#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,x,y,i,sum,n;
signed main(){
	freopen("0.in","r",stdin);freopen("0.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>x;sum+=x;
		cout<<(sum+(i-1))/i<<' ';
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
