#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans[29],last[29];
int T,i,ANS;
char c[200009];
int n;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		for(i=1;i<=26;i++)ans[i]=999999LL,last[i]=0;
		cin>>n;getchar();
		for(i=1;i<=n;i++){
			c[i]=getchar();
		}
		for(i=n+1;i<=2*n;i++){
			c[i]=c[i-n];
		}
		for(i=1;i<=2*n;i++){
			if(last[c[i]-'a'+1]==0){
				last[c[i]-'a'+1]=i;
			}
			else{
				ans[c[i]-'a'+1]=min(ans[c[i]-'a'+1],i-last[c[i]-'a'+1]-1);
				last[c[i]-'a'+1]=i;
			}
		}
		ANS=999999LL;
		for(i=1;i<=26;i++){
			ANS=min(ANS,ans[i]);
		}
		if(ANS==999999){
			printf("-1\n");
		}
		else{
			printf("%lld\n",ANS);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
