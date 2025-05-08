#include<bits/stdc++.h>
using namespace std;
int a[100009],sum,n,i;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=n;i++)sum^=a[i];
    cout<<sum<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
