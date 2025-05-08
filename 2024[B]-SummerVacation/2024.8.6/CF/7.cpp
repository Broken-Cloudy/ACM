#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
void dfs(int l,int r){
	if(l==r){
		printf("! %lld\n",l);fflush(stdout);
		return;
	}
	else if(l+1==r){
		printf("! %lld\n",r);fflush(stdout);
		return;
	}
	int x;
	int mid=(l+r)/2;
	printf("? %lld %lld\n",1,mid);fflush(stdout);
	scanf("%lld",&x);
	if(x==mid+1){
		dfs(l,mid);
	}
	else if(x==mid){
		dfs(mid+1,r);
	}
}
signed main(){
	//freopen("7.in","r",stdin);freopen("7.out","w",stdout);
	cin>>T;
	while(T--){
		dfs(1,999);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
