#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,T,a[200009],i,b[200009],pre[200009],suf[200009],sum,FF,l,r;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);FF=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++){
			if(a[i]<=k)b[i]=1;
			else b[i]=-1;
		}
		l=n;r=1;
		pre[0]=0;for(i=1;i<=n;i++)pre[i]=pre[i-1]+b[i];
		for(i=1;i<=n-2;i++)if(pre[i]>=0){l=i;break;}
		suf[n+1]=0;for(i=n;i>=1;i--)suf[i]=suf[i+1]+b[i];
		for(i=n;i>=3;i--)if(suf[i]>=0){r=i;break;}
		for(i=n-2;i>=1;i--)pre[i]=max(pre[i],pre[i+1]);
		for(i=3;i<=n;i++)suf[i]=max(suf[i-1],suf[i]);
		sum=0;
		for(i=1;i<=n-2;i++){
			sum+=b[i];
			if(sum>=0&&(pre[i+1]-sum)>=0){
				FF=1;
			}
		}
		sum=0;
		for(i=n;i>=3;i--){
			sum+=b[i];
			if(sum>=0&&(suf[i-1]-sum)>=0){
				FF=1;
			}
		}
		if(r-l>=2)FF=1;
		if(FF==1)printf("YES\n");
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
