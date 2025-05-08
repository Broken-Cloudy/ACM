#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,a[59],maxx,ans,b[59],cnt;
bool f=0;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld",&n);
		memset(b,0,sizeof(b));
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		sort(a+1,a+1+n);
		maxx=a[n];
		cnt=0;
		b[++cnt]=1;
		for(i=n-1;i>=1;i--){
			if(a[i]!=maxx){
				b[++cnt]=1;
				maxx=a[i];
			}
			else{
				b[cnt]++;
			}
		}
		f=0;
		for(i=1;i<=cnt;i++){
			if(i%2==1&&b[i]%2==1){
				f=1;break;
			}
			else if(i%2==0&&b[i]%2==1){
				f=1;break;
			}
		}
		if(f==1)printf("YES\n");
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

