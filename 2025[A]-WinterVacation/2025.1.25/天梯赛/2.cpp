#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,maxx,ans[1009],i,kk;
int check(int x){
	int t,y,pi,anss=0;
	while(x>10){
		y=x;pi=1;anss++;
		while(y>0){
			pi*=(y%10);
			y/=10;
		}
		x=pi;
	}
	return anss;
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>a>>b;
	for(i=a;i<=b;i++){
		int kk=check(i);
		if(kk>maxx){
			ans[0]=0;
			maxx=kk;
			ans[++ans[0]]=i;
		}
		else if(kk==maxx){
			ans[++ans[0]]=i;
		}
	}
	printf("%lld\n",maxx);sort(ans+1,ans+1+ans[0]);
	for(i=1;i<=ans[0];i++){
		if(i==ans[0])printf("%lld\n",ans[i]);
		else printf("%lld ",ans[i]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
