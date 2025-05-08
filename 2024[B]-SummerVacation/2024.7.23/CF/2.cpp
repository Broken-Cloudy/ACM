#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,i,j,a[200009],k,sum,ans;
queue<int>q;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		sort(a+1,a+1+n);
		while(!q.empty())q.pop();
		sum=0;ans=0;
		for(i=1;i<=n;i++){
			sum+=a[i];
			q.push(a[i]);
			if(i>1)while((q.front()!=q.back())&&(q.front()!=q.back()-1)){
				int t=q.front();
				sum-=t;
				q.pop();
			}
			while(sum>m){
				int t=q.front();
				sum-=t;
				q.pop();
			}
			ans=max(sum,ans);
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
