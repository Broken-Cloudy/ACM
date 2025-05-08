#include<bits/stdc++.h>
using namespace std;
bool f[1200];
char c;
int n,i,ans;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;getchar();
	for(i=1;i<=n;i++){
		c=getchar();
		if(f[c]==0)ans+=2,f[c]=1;
		else ans++;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
