#include<bits/stdc++.h>
#define int long long
using namespace std;
char c[100009];
int i,n,kk;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;getchar();
	for(i=1;i<=n;i++)c[i]=getchar();
	if(n==1)printf("YES\n");
	else{
		for(i=1;i<n;i++){
			if(c[i]==c[i+1])kk++;
		}
		if(kk<=1)printf("YES\n");
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
