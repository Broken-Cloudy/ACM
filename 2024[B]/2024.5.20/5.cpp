#include<bits/stdc++.h>
using namespace std;
int f[1009],k,i,n,ans;
int main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		f[k]++;
	}
	for(i=100;i<=299;i++){
		if(f[i]!=0||f[500-(i-100)]!=0){
			ans=f[i]+f[500-(i-100)];
		}
	}
	if(f[300]!=0)ans=f[300];
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
