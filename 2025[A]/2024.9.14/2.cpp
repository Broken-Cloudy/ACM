#include<bits/stdc++.h>
#define int long long
using namespace std;
deque<int>q;
int n,a[100009],d[100009],di[100009],i,ans,sum[100009];
void pre(){
	int i,t,ji;//这些都是a[]的序号 
	for(i=1;i<=n;i++){
		if(!q.empty())t=q.back();ji=1;
		while(!q.empty()&&a[i]<a[t]){ 
			d[t]=(i-1);
			ji+=di[t];
			q.pop_back();
			if(!q.empty())t=q.back();
		}
		di[i]=ji;
		q.push_back(i);
	}
	if(!q.empty())t=q.back();
	while(!q.empty()){
		d[t]=(i-1);
		q.pop_back();
		if(!q.empty())t=q.back();
	}
	for(i=1;i<=n;i++){
		di[i]=i-di[i]+1;
	}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	pre();
	for(i=1;i<=n;i++){
		ans=max(ans,(sum[d[i]]-sum[di[i]-1])*a[i]);
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
