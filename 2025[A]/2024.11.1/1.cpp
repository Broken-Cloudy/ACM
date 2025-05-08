#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,x,y,z,k,ans,i;
int work(int DMG){
	int ANS;
	int DHP;
	DHP=k*(1+DMG/k)*(DMG/k)/2;
	ANS=DMG*x+y*((z-DHP+DMG-1)/DMG)+(DMG/k)*y;
	return ANS;
}
void dfs(int l,int r){
	int i;
	int part1=l+(r-l)*1/3;
	int part2=l+(r-l)*2/3;
	if(r-l<=500000){
		for(i=l;i<=r;i++){
			if(work(i-1)>work(i))printf("%lld ",i);
			ans=min(ans,work(i));
		}
		return;
	}
	if(work(part1)>work(part2)){
		dfs(part1,r);
	}
	else{
		dfs(l,part2);
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>x>>y>>z>>k;
		ans=1000000000000000009LL;
		if(k<=10000)dfs(1,z);
		else{
			
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
