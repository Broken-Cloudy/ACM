#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,a[100009],GCD,E,ans,vis[100009],miniGCD,bh,nowGCD;
void gcd(int a,int b){
	if(b==0){
		GCD=a;
		return;
	}
	else gcd(b,a%b);
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++)scanf("%lld",&a[i]),vis[i]=0;ans=0;
		GCD=a[1];for(i=2;i<=n;i++)gcd(GCD,a[i]);E=GCD;
		for(i=1;i<=n;i++)a[i]/=GCD;
		sort(a+1,a+1+n);vis[1]=1;miniGCD=a[1];ans+=miniGCD;
		while(miniGCD>1){
			nowGCD=miniGCD;
			for(i=1;i<=n;i++){
				if(!vis[i]){
					gcd(miniGCD,a[i]);
					if(GCD<nowGCD){
						bh=i;
						nowGCD=GCD;
					}
				}
			}
			vis[bh]=1;
			gcd(miniGCD,a[bh]);miniGCD=GCD;
			ans+=miniGCD;
		}
		for(i=1;i<=n;i++){
			if(!vis[i])ans++;
		}
		printf("%lld\n",ans*E);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
