#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,n,x,y,ans,K,hui;
int check(int att,int shen,int huihe){
	int anss=0;
	if(shen>=huihe){
		anss=huihe*(att+1);
	}
	else{
		anss=shen*(att+1);
		huihe-=shen;
		if(huihe>=att){
			anss+=att*(att+1)/2;
		}
		else{
			anss+=huihe*(att+att-huihe+1)/2;
		} 
	}
	return anss;
}
signed main(){
	freopen("7.in","r",stdin);freopen("7.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&x,&y);ans=0;
		for(i=0;i<=y;i++){
			K=x+i;//当前攻击力
			j=y-i;//剩余磨刀石数量
			hui=n-i;//剩余回合数
			ans=max(ans,check(K,j,hui));
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
