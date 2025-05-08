#include<bits/stdc++.h>
using namespace std;
int x[100009],a,b,c,i,n,ans;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>a>>b>>c;
	cin>>n;
	for(i=1;i<=n;i++)scanf("%d",&x[i]);
	for(i=1;i<=n;i++){
		if(x[i]>b||x[i]<c)ans++;
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
