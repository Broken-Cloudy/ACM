#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
struct ask{
	int x,v;
};
struct segment_tree{
	int sum,cnt;
};
segment_tree tree[8000009];
ask q[200009];
int n,m,Q,a[200009],b[800009],cnt,i,sum,t;
void pushup(int node,int start,int end){
	int zuo=node*2;
	int you=node*2+1;
	if(start!=end){
		tree[node].sum=tree[zuo].sum+tree[you].sum;
		tree[node].cnt=tree[zuo].cnt+tree[you].cnt;
	}
}
void change(ll node,ll start,ll end,ll X,ll k){
	if(end<X||start>X)return;//加速操作!!!
	else if(start==X&&end==X){
		tree[node].sum+=k;
		if(k>0)tree[node].cnt++;
		else tree[node].cnt--;
		pushup(node,start,end);
		return;//记得return 
	} 
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change(zuo,start,mid,X,k);
		change(you,mid+1,end,X,k);
		pushup(node,start,end);
	}
}
int find_sum(ll node,ll start,ll end,ll L,ll R){
	if(L>R)return 0;
	if(end<L||start>R)return 0;//加速操作!!!
	else if(start>=L&&end<=R){
		return tree[node].sum;
	} 
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		return find_sum(zuo,start,mid,L,R)+find_sum(you,mid+1,end,L,R);
	}
}
int find_cnt(ll node,ll start,ll end,ll L,ll R){
	if(L>R)return 0;
	if(end<L||start>R)return 0;//加速操作!!!
	else if(start>=L&&end<=R){
		return tree[node].cnt;
	} 
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		return find_cnt(zuo,start,mid,L,R)+find_cnt(you,mid+1,end,L,R);
	}
}
int dfs(int l,int r,int S){
	if(l==r)return l;
	else if(l+1==r){
		if(find_sum(1,1,cnt,1,l)<S)return r;
		else return l;
	}
	else{
		int mid=(l+r)/2;
		if(find_sum(1,1,cnt,1,mid)>=S){
			return dfs(l,mid,S);
		}
		else return dfs(mid,r,S);
	}
}
int work(int SUM){
	int ansX=dfs(1,cnt,SUM);
	if(ansX==1){
		int kk=find_cnt(1,1,cnt,1,1);
		return min(SUM/max(1LL,b[1]),kk)+1;
	}
	int kk1=find_cnt(1,1,cnt,1,ansX-1);
	int kk2=find_cnt(1,1,cnt,ansX,ansX);
	return min((SUM-find_sum(1,1,cnt,1,ansX-1))/max(1LL,b[ansX]),kk2)+1LL+kk1;
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n>>Q;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]>0)b[++cnt]=a[i];
		else sum+=a[i];
	}
	for(i=1;i<=Q;i++){
		scanf("%lld%lld",&q[i].x,&q[i].v);
		if(q[i].v>0)b[++cnt]=q[i].v;
	}
	sort(b+1,b+1+cnt);
	cnt=unique(b+1,b+1+cnt)-(b+1);
	for(i=1;i<=n;i++){
		t=lower_bound(b+1,b+1+cnt,a[i])-b;
		if(a[i]>0)change(1,1,cnt,t,a[i]);
	}
	for(i=1;i<=Q;i++){
		if(a[q[i].x]<=0&&q[i].v<=0){
			sum-=a[q[i].x];sum+=q[i].v;
		}
		else if(a[q[i].x]>0&&q[i].v<=0){
			t=lower_bound(b+1,b+1+cnt,a[q[i].x])-b;
			change(1,1,cnt,t,-a[q[i].x]);
			sum+=q[i].v;
		}
		else if(a[q[i].x]<=0&&q[i].v>0){
			sum-=a[q[i].x];
			t=lower_bound(b+1,b+1+cnt,q[i].v)-b;
			change(1,1,cnt,t,q[i].v);
		}
		else{
			t=lower_bound(b+1,b+1+cnt,a[q[i].x])-b;
			change(1,1,cnt,t,-a[q[i].x]);
			t=lower_bound(b+1,b+1+cnt,q[i].v)-b;
			change(1,1,cnt,t,q[i].v);
		}
		a[q[i].x]=q[i].v;
		printf("%lld\n",work(-sum));
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
