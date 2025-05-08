#include<bits/stdc++.h>
using namespace std;
int n,k,ans,i;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		if(k!=1)ans++;
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
