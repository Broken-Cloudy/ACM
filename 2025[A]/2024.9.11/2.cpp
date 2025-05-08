#include<bits/stdc++.h>
#define int long long
#define lc(x) tree[x].ch[0]
#define rc(x) tree[x].ch[1]
using namespace std;
struct nod{
	int ch[2];
};
const int inf=9712176LL;
nod tree[1000009];
deque<int>q;//编号双头栈 
int n,i,a[1000009],cnt,k,c[1000009],d[1000009];
int ci[1000009],di[1000009]; 
void pre(){
	int i,t,ji;//这些都是a[]的序号 
	for(i=1;i<=n;i++){
		if(!q.empty())t=q.back();ji=1;
		while(!q.empty()&&a[i]<a[t]){//小序列 
			d[t]=di[t]*(i-t);d[t]%=inf;
			ji+=di[t];
			q.pop_back();
			if(!q.empty())t=q.back();
		}
		di[i]=ji;
		q.push_back(i);
	}
	if(!q.empty())t=q.back();
	while(!q.empty()){//小序列 
		d[t]=di[t]*(i-t);
		q.pop_back();
		if(!q.empty())t=q.back();
	}
	for(i=1;i<=n;i++){
		if(!q.empty())t=q.back();ji=1;
		while(!q.empty()&&a[i]>a[t]){//大序列 
			c[t]=ci[t]*(i-t);c[t]%=inf;
			ji+=ci[t];
			q.pop_back();
			if(!q.empty())t=q.back();
		}
		ci[i]=ji;
		q.push_back(i);
	}
	if(!q.empty())t=q.back();
	while(!q.empty()){//小序列 
		c[t]=ci[t]*(i-t);
		q.pop_back();
		if(!q.empty())t=q.back();
	}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	pre();
	fclose(stdin);fclose(stdout);
	return 0;
}
