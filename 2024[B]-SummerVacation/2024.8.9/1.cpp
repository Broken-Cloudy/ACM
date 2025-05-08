#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int T,n,m,i,x,y,cnt,ans;
struct scanline{
	int x,l,r,mark;
};
scanline a[1600009];
struct segment_tree{
	int cnt,len;
};
segment_tree tree[1600009];
bool cmp(scanline x,scanline y){
	return x.x<y.x;
}
void pushup(int node,int start,int end){
	int zuo=node*2;
	int you=node*2+1;
	if(tree[node].cnt>0)tree[node].len=end-start+1;
	else tree[node].len=tree[zuo].len+tree[you].len;
}
void change(ll node,ll start,ll end,ll L,ll R,ll k){
	if(end<L||start>R)return;//加速操作!!!
	else if(start>=L&&end<=R){
		tree[node].cnt+=k;
		pushup(node,start,end);//必操作!!!
		return;//记得return 
	} 
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change(zuo,start,mid,L,R,k);
		change(you,mid+1,end,L,R,k);
		pushup(node,start,end);
	}
}
void build(int cnt){
	int i;
	for(i=1;i<=cnt;i++){
		if(a[i].mark==1){	
			change(1,1,n,a[i].l,a[i].r-1,1);
		}
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);cnt=0;
		for(i=1;i<=8*n;i++)tree[i].cnt=0,tree[i].len=0;
		for(i=1;i<=m;i++){
			scanf("%lld%lld",&x,&y);
			cnt++;a[cnt].x=x;a[cnt].l=x;a[cnt].r=y;a[cnt].mark=1;
			cnt++;a[cnt].x=y;a[cnt].l=x;a[cnt].r=y;a[cnt].mark=-1;
		}
		sort(a+1,a+1+cnt,cmp);
		build(cnt);//生成禁用n-->1的线段树 
		ans=tree[1].len;
		for(i=1;i<cnt;i++){
			if(a[i].mark==1){
				change(1,1,n,a[i].l,a[i].r-1,-1);
				change(1,1,n,1,a[i].l-1,1);
				change(1,1,n,a[i].r,n,1);
			}
			else{
				change(1,1,n,a[i].l,a[i].r-1,1);
				change(1,1,n,1,a[i].l-1,-1);
				change(1,1,n,a[i].r,n,-1);
			}
			ans=min(ans,tree[1].len);
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
