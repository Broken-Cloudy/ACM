#include<bits/stdc++.h>
#define int long long
using namespace std;
int N,i,x,vis[100009],cnt;
struct nod{
	int bh,val;
}t,Mid,d;
struct cmp1{
	bool operator()(nod x,nod y){
		return x.val<y.val;
	}
};
struct cmp2{
	bool operator()(nod x,nod y){
		return x.val>y.val;
	}
};
string s;
deque<nod>q;
priority_queue<nod,vector<nod>,cmp1>q1;
priority_queue<nod,vector<nod>,cmp2>q2;
signed main(){
	freopen("158.in","r",stdin);freopen("158.out","w",stdout);
	cin>>N;
	for(i=1;i<=N;i++){
		cin>>s;
		cnt=q.size();
		if(s=="Pop"){
			if(cnt==0){
				printf("Invalid\n");
				continue;
			}
			d=q.back();q.pop_back();
			printf("%lld\n",d.val);
			if(cnt%2==0){
				if(d.val<=Mid.val){
					q1.push(Mid);
					while(!q2.empty()){
						t=q2.top();q2.pop();
						if(vis[t.bh]==0){
							Mid=t;
							break;
						}
					}
				}
				vis[d.bh]=1;
			}
			else{
				if(d.val>=Mid.val){
					q2.push(Mid);
					while(!q1.empty()){
						t=q1.top();q1.pop();
						if(vis[t.bh]==0){
							Mid=t;
							break;
						}
					}
				}
				vis[d.bh]=1;
			}
		}
		else if(s=="PeekMedian"){
			if(cnt==0)printf("Invalid\n");
			else printf("%lld\n",Mid.val);
		}
		else{
			scanf("%lld",&x);d.val=x;d.bh=i;
			cnt=q.size();q.push_back(d);
			if(cnt==0){
				Mid=d;
				continue;
			}
			if(cnt%2==0){
				if(d.val>=Mid.val){
					q1.push(Mid);
					q2.push(d);
					while(!q2.empty()){
						t=q2.top();q2.pop();
						if(vis[t.bh]==0){
							Mid=t;
							break;
						}
					}
				}
				else q1.push(d);
			}
			else{
				if(d.val<=Mid.val){
					q2.push(Mid);
					q1.push(d);
					while(!q1.empty()){
						t=q1.top();q1.pop();
						if(vis[t.bh]==0){
							Mid=t;
							break;
						}
					}
				}
				else q2.push(d);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
