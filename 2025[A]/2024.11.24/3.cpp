#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXX=2e6+9;
int i,j,n,q,r[MAXX],e[MAXX],d[MAXX],ans1,ans2,x;
char s[MAXX],t[MAXX];
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n>>q;
	getchar();for(i=1;i<=n;i++)s[i]=getchar();
	getchar();for(i=1;i<=n;i++)t[i]=getchar();
	while(q--){
		scanf("%lld",&x);
		ans1=ans2=0;
		swap(s[x],t[x]);
		for(i=1;i<=n;i++){
			if(s[i]=='r')r[i]=r[i-1]+1;
			else r[i]=r[i-1];
		}
		for(i=n;i>=1;i--){
			if(s[i]=='d')d[i]=d[i+1]+1;
			else d[i]=d[i+1];
		}
		for(i=1;i<=n;i++){
			if(s[i]=='e'){
				ans1+=r[i]*d[i];
			}
		}
		for(i=1;i<=n;i++){
			if(t[i]=='r')r[i]=r[i-1]+1;
			else r[i]=r[i-1];
		}
		for(i=n;i>=1;i--){
			if(t[i]=='d')d[i]=d[i+1]+1;
			else d[i]=d[i+1];
		}
		for(i=1;i<=n;i++){
			if(t[i]=='e'){
				ans2+=r[i]*d[i];
			}
		}
		printf("%lld\n",ans1-ans2);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
