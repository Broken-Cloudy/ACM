#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans,i;
char c[100009];
signed main(){
	freopen("7.in","r",stdin);freopen("7.out","w",stdout);
	scanf("%s",c+1);
	int n=strlen(c+1);
	for(i=1;i<=n;i++){
		if(c[i]!='R')ans++;
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
