#include<bits/stdc++.h>
#define ll int
using namespace std;
deque<pair<int,int>>d;
pair<int,int>t;
struct scanline{
	int r_left,r_right;
	int l,mark;
}S[1000009];
int T,i,n,a[500009],zuo[500009],bh[500009],zuocnt,you[500009],BH[500009],youcnt;
int tree[4000009],tag[4000009],f[500009],cnt,r_l,r_r,l_l,l_r,ANS,ans1,ans2;
int ff;
bool cmp(scanline x,scanline y){
	return x.l<y.l;
}
void PRE(){
	for(i=1;i<=8*n;i++)tag[i]=tree[i]=0;
	zuocnt=youcnt=0;
	for(i=n;i>=1;i--){//针对左 
		f[i]=0;
		while(!d.empty()){
			t=d.back();
			if(t.first>=a[i])d.pop_back();
			else break;
		}
		d.push_back(make_pair(a[i],i));
	}
	while(!d.empty()){//形成单调减 
		t=d.back();d.pop_back();
		zuocnt++;
		zuo[zuocnt]=t.first;
		bh[zuocnt]=t.second;f[t.second]=1;
	}
	for(i=1;i<=n;i++){//针对右 
		while(!d.empty()){
			t=d.back();
			if(t.first<=a[i])d.pop_back();
			else break;
		}
		d.push_back(make_pair(a[i],i));
	}
	while(!d.empty()){//形成单调增 
		t=d.front();d.pop_front();
		youcnt++;
		you[youcnt]=t.first;
		BH[youcnt]=t.second;f[t.second]=1;
	}
}
void add_tag(ll node,ll start,ll end,ll k){//懒人标记 
	tag[node]+=k;
	tree[node]+=k;//先把本层给加了，下面的层数先不加，打个标记 
	return;
}
void pushdown(ll node,ll start,ll end){//只需执行一次 
	if(tag[node]==0)return;//没有标记，不需要考虑
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		ll t=tag[node];
		add_tag(zuo,start,mid,t);//标记下传(标记并不是去除，而是下传) 
		add_tag(you,mid+1,end,t);//标记下传(标记并不是去除，而是下传) 
		tag[node]=0;//标记清空 
	} 
}
void change(ll node,ll start,ll end,ll L,ll R,ll k){
	if(end<L||start>R)return;//加速操作!!!
	else if(start>=L&&end<=R){
		add_tag(node,start,end,k);
		return;//记得return 
	} 
	else{
		pushdown(node,start,end);//加值的时候也要下传，细化，否则可能会影响结果 
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change(zuo,start,mid,L,R,k);
		change(you,mid+1,end,L,R,k);
		tree[node]=max(tree[zuo],tree[you]);
	}
}
ll sum(ll node,ll start,ll end,ll L,ll R){
	pushdown(node,start,end);//NlogN次 
	if(end<L||start>R)return 0;//加速操作!!!
	else if(start>=L&&end<=R)return tree[node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=sum(zuo,start,mid,L,R);
		ll y=sum(you,mid+1,end,L,R);
		return max(x,y);
	}
}
void dfs1(int l,int r,int x){
	if(zuo[r]>=x){
		ans1=r+1;
		return;
	}
	if(l==r){
		ans1=l;
	}
	else if(l==r-1){
		if(zuo[l]>=x)ans1=r;
		else ans1=l;
	}
	else{
		int mid=(l+r)/2;
		if(zuo[mid]>x)dfs1(mid,r,x);
		else dfs1(l,mid,x);
	}
	return;
}
void dfs2(int l,int r,int x){
	if(you[l]<=x){
		ans2=l-1;
		return;
	}
	if(l==r){
		ans2=l;
	}
	else if(l==r-1){
		if(you[r]<=x)ans2=l;
		else ans2=r;
	}
	else{
		int mid=(l+r)/2;
		if(you[mid]>x)dfs2(mid,r,x);
		else dfs2(l,mid,x);
	}
	return;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%d",&n);cnt=0;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		if(n==1)ff=-1;
		else ff=1;
		for(i=2;i<=n;i++)if(a[i]>a[i-1])ff=0;
		if(ff==1||ff==-1){
			printf("1\n");
			continue;
		}
		else ANS=2;
		PRE();
		for(i=1;i<=n;i++){//构造扫描线 
			if(f[i]==0){
				r_l=lower_bound(BH+1,BH+1+youcnt,i)-BH;
				dfs2(1,youcnt,a[i]);r_r=ans2;
				if(r_l>r_r)continue;
				dfs1(1,zuocnt,a[i]);l_l=ans1;
				l_r=lower_bound(bh+1,bh+1+zuocnt,i)-bh;
				if(l_l>=l_r)continue;
				cnt++;S[cnt].r_left=r_l;S[cnt].r_right=r_r;S[cnt].l=l_l;S[cnt].mark=1;
				cnt++;S[cnt].r_left=r_l;S[cnt].r_right=r_r;S[cnt].l=l_r;S[cnt].mark=-1;
			}
		}
		sort(S+1,S+1+cnt,cmp);
		for(i=1;i<=cnt+1;i++){
			if(S[i].l!=S[i-1].l||i==cnt+1)ANS=max(ANS,sum(1,1,youcnt,1,youcnt)+2);
			if(i<=cnt)change(1,1,youcnt,S[i].r_left,S[i].r_right,S[i].mark);
		}
		printf("%d\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
