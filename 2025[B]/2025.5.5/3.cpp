#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=-4000000000000LL;
int T,n,i,j,k,a[200009],maxx,anss;
int ans1,ans2;
string s;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);
		cin>>s;s=" "+s;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++){
			if(s[i]=='0')a[i]=P;
		}
		maxx=0;anss=0;
		for(i=1;i<=n;i++){
			if(maxx<=0)maxx=0;
			maxx+=a[i];
			anss=max(anss,maxx);
		}
		if(anss>k){
			printf("No\n");
		}
		else if(anss==k){
			printf("Yes\n");
			for(i=1;i<=n;i++){
				if(i==n)printf("%lld\n",a[i]);
				else printf("%lld ",a[i]);
			}
		}
		else{
			for(i=1;i<=n;i++){
				if(s[i]=='0'){
					ans1=ans2=0;
					maxx=0;
					for(j=i-1;j>=1;j--){
						maxx+=a[j];
						ans1=max(ans1,maxx);
					}
					maxx=0;
					for(j=i+1;j<=n;j++){
						maxx+=a[j];
						ans2=max(ans2,maxx);
					}
					a[i]=k-(ans1+ans2);
					break;
				}
			}
			maxx=0;anss=0;
			for(i=1;i<=n;i++){
				if(maxx<=0)maxx=0;
				maxx+=a[i];
				anss=max(anss,maxx);
			}
			if(anss==k){
				printf("Yes\n");
				for(i=1;i<=n;i++){
					if(i==n)printf("%lld\n",a[i]);
					else printf("%lld ",a[i]);
				}
			}
			else printf("No\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
