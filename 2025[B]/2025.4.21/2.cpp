#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,ans,f1,f2,f3,kk;
char c[200009],now='0';
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		f1=f2=f3=0;ans=0;kk=0;now='0';c[0]='0';
		scanf("%lld",&n);getchar();
		for(i=1;i<=n;i++)c[i]=getchar();
		for(i=0;i<=n;i++){
			if(c[i]=='0'&&c[i+1]=='1'&&i<n){
				if(f1==1)kk=2;
				f1=1;
				if(f3==1)kk=max(kk,1LL);f3=1;
			}
			if(c[i]=='1'&&c[i+1]=='0'&&i<n){
				if(f2==1)kk=2;
				f2=1;
				kk=max(kk,1LL);
			}
			if(c[i]==now){
				if(i>=1)ans++;	
			}
			else{
				if(i>=1)ans+=2;
				if(now=='0')now='1';
				else now='0';
			}
		}
		printf("%lld\n",ans-kk);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
