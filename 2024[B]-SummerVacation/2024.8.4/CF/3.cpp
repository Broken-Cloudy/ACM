#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,a[200009],i,b[800009],ans,maxx,r,num,p;
bool f=0;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		maxx=0;
		scanf("%lld%lld",&n,&k);
		for(i=0;i<=4*n;i++){
			b[i]=0;
		}
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			maxx=max(a[i],maxx);
		}
		sort(a+1,a+1+n);
		num=maxx;
		maxx%=(2*k);
		for(i=1;i<=n;i++){
			b[a[i]%(2*k)]++;
			b[a[i]%(2*k)+2*k]++;
		}
		if(maxx<k)maxx+=2*k;
		p=0;
		for(i=maxx-k+1;i<=maxx;i++){
			p+=b[i];
		}
		i=1;ans=-1;
		while(i<=k){
			if(p==n){
				ans=i-1;
				break;
			}
			if(i==k)break;
			else{
				p-=b[maxx-k+i];
				p+=b[maxx+i];
			}
			i++;
		}
		if(ans<0){
			printf("-1\n");
		}
		else printf("%lld\n",num+ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
