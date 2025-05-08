#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,k,a[200009],kk,lastkk,ans,t,d;
priority_queue<int,vector<int>,less<int>>q1;//小根大顶堆 
priority_queue<int,vector<int>,greater<int>>q2;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		while(!q1.empty())q1.pop();while(!q2.empty())q2.pop();
		scanf("%lld%lld",&n,&k);lastkk=0;ans=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=n;i>=1;i--){
			kk=(n-i+1)/(k+1);//可以拿kk盘 
			q1.push(a[i]);
			if(kk==lastkk+1){
				t=q1.top();
				q2.push(t);ans+=t;
			}
			else{
				if(!q2.empty()){
					t=q1.top();d=q2.top();
					if(t>d){
						q2.pop();
						ans+=(t-d);
						q2.push(t);
					}
				}
			}
			lastkk=kk;q1.pop();
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
