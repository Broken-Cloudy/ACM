#include<iostream>
#include<algorithm>
#define int long long
#define ll long long
using namespace std;
int n,i,x1,x2,y1,y2,cnt,X[1800009],xcnt,ans;
struct scanline{
	int x_left,x_right,y;
	int mark;
};
scanline a[1800009];
bool cmp(scanline x,scanline y){
	return x.y<y.y;
}
struct segment_tree{
	int l,r;
	int cnt,len;//len是当前的节点的覆盖长度，cnt是 是否覆盖，覆盖了几次 
};
segment_tree tree[1800009];
void build(ll node,ll start,ll end){
	tree[node].l=start;tree[node].r=end;
	if(start==end){
		return;
	}
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		build(zuo,start,mid);
		build(you,mid+1,end);
	}
}
void pushup(int node,int start,int end){
	int l=tree[node].l;
	int r=tree[node].r;
	int zuo=node*2;
	int you=node*2+1;
	if(tree[node].cnt>0)tree[node].len=X[r+1]-X[l];
	else tree[node].len=tree[zuo].len+tree[you].len;
}
void change(ll node,ll start,ll end,ll L,ll R,ll k){
	if(end<L||start>R)return;//加速操作!!!
	else if(start>=L&&end<=R){
		tree[node].cnt+=k;
		pushup(node,start,end);//加速操作!!!
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
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);X[2*i-1]=x1;X[2*i]=x2;
		cnt++;a[cnt].x_left=x1;a[cnt].x_right=x2;a[cnt].y=y1;a[cnt].mark=1;
		cnt++;a[cnt].x_left=x1;a[cnt].x_right=x2;a[cnt].y=y2;a[cnt].mark=-1;
	}
	sort(a+1,a+1+cnt,cmp);
	//离散化 
	sort(X+1,X+1+(2*n));
	xcnt=unique(X+1,X+1+(2*n))-(X+1);//去重
	//右端点偏移映射  [l,r]-->[X[l],X[r+1]] eg:[1,1]-->[X[1],X[2]]
	//传参时,[X[1],X[2]]-->[l,r-1](二分查找l与r) 
	////不能一一对应，应该是对应从这个点，到下一个点的区间 
	build(1,1,xcnt-1);//树的离散化对应 
	for(i=1;i<cnt;i++){
		int l=lower_bound(X+1,X+1+xcnt,a[i].x_left)-X;
		int r=lower_bound(X+1,X+1+xcnt,a[i].x_right)-X;
		change(1,1,xcnt-1,l,r-1,a[i].mark);
		//(a[i+1].y-a[i].y)这个是宽度 
		//tree[1].len当前的总长度 
		ans+=1LL*tree[1].len*(a[i+1].y-a[i].y);
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
