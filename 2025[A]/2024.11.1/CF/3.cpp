#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,k,a[200009],ans,cnt,x,y,z;
deque<int>q;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ans=0;cnt=0;
		while(!q.empty())q.pop_back();
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		sort(a+1,a+1+n);
		for(i=1;i<=n;i++){
			while(cnt>=2){
				x=q.front();z=a[i];q.pop_front();
				y=q.front();
				if(y>z-x){
					q.push_front(x);
					break;
				}
				else{
					cnt--;
				}
			}
			q.push_back(a[i]);cnt++;
			ans=max(ans,cnt);
		}
		ans=n-ans;
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
