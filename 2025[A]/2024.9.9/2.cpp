#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,op,k;
priority_queue<int,vector<int>,greater<int> >q;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&op);
		if(op==1){
			scanf("%lld",&k);
			q.push(k);
		}
		else if(op==2){
			int t=q.top();
			printf("%lld\n",t);
		}
		else{
			q.pop();
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
