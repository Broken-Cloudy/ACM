#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,w;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>a>>b>>w;
	if(a+b==w){
		printf("Yes\n");
	}
	else if(a==w||b==w){
		printf("Yes\n");
	}
	else if(a==w+b||b==w+a){
		printf("Yes\n");
	}
	else printf("No\n");
	fclose(stdin);fclose(stdout);
	return 0;
}
