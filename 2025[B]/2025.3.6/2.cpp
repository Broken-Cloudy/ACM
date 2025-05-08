#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,a[1009],vis[1009],t1,t2;
priority_queue<int,vector<int>,greater<int>>q;
bool FF;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);FF=1;
		while(!q.empty())q.pop();
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++)q.push(a[i]),vis[i]=0;
		while(!q.empty()){
			t1=q.top();q.pop();
			if(vis[t1]==0){
				t2=q.top();q.pop();
				if(t1==t2){
					vis[t1]=1;
				}
				else{
					FF=0;
					break;
				}
			}
			else{
				t1++;q.push(t1);
			}
		}
		if(FF==1)printf("YES\n");
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
