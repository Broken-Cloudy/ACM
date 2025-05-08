#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200009],b[200009],i,n,ANS;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=1;i<=n;i++)scanf("%lld",&b[i]);
	for(i=1;i<=n;i++){
		if(a[i]>b[i])ANS+=b[i];
		else ANS+=a[i];
	}
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
