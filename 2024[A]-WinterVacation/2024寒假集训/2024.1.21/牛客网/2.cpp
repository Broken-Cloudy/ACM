#include<bits/stdc++.h>
using namespace std;
int n,ans,i;
char a[100010],b[100010];
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	scanf("%s",a+1);scanf("%s",b+1);
	for(i=1;i<=n;i++){
		if(a[i]=='N'&&b[i]=='Y')ans+=2;
		else if(a[i]=='Y'&&b[i]=='Y')ans+=3;
		else if(a[i]=='Y'&&b[i]=='N')ans+=2;
		else ans+=0;
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
