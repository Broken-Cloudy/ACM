#include<bits/stdc++.h>
#define ll long long
using namespace std;
const long long inf=1e9+7;
ll f[100009],num,i,n,m;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>m;num=n-m;
	for(i=1;i<=m;i++){
		f[i]=f[i-1]+i;
	}
	if(num==0)printf("1\n");
	else{
		
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
