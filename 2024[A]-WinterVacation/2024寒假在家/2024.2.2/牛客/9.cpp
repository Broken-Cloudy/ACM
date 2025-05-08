#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n,i,a,b,r,ans,x,y;
int main(){
	freopen("9.in","r",stdin);freopen("9.out","w",stdout);
	ans=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		scanf("%lld%lld%lld",&x,&y,&r);
		if(max(x,-x)>=99&&max(y,-y)>=99){
			ans++;
		}
	}
	if(ans>=4){
		printf("bit-noob\n");
	}
	else printf("buaa-noob\n");
	fclose(stdin);fclose(stdout);
	return 0;
}
