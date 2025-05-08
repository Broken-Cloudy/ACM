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
int det(int DMG){
	int ANS;
	int DHP;
	DHP=k*(1+DMG/k)*(DMG/k)/2;
	ANS=(z-DHP+DMG-1)/DMG;
	return ANS;
}
int add(int DMG){
	int x,y;
	if(DMG==z)return 1LL;
	x=(DMG/k+1)*k-DMG;
	y=z-k*(1+(DMG/k))*(DMG/k)/2;
	if(det(DMG)!=det(DMG+1)){
		return 1LL;
	}
	else{
		if(det(DMG)==1)y=1000000000000000009LL;
		else{
			y=y/(det(DMG)-1);
			if((z-k*(1+(y/k))*(y/k)/2)%y!=0){
				y++;
			}
			y-=DMG;
		}
	}
	return max(1LL,min(x,y));
}
void dfs(int l,int r){
	int i;
	int part1=l+(r-l)*1/3;
	int part2=l+(r-l)*2/3;
	if((r-l<=10000000||l>=1000)&&k>=50000){
		for(i=l;i<=r;i+=add(i)){
			ans=min(ans,work(i));
		}
		return;
	}
	if(r-l<=400000){
		for(i=l;i<=r;i++){
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
		if(k<=50000)dfs(1,z);
		else{
			dfs(1,z);
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
