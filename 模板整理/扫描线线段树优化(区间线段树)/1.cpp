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
	int cnt,len;//len�ǵ�ǰ�Ľڵ�ĸ��ǳ��ȣ�cnt�� �Ƿ񸲸ǣ������˼��� 
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
	if(end<L||start>R)return;//���ٲ���!!!
	else if(start>=L&&end<=R){
		tree[node].cnt+=k;
		pushup(node,start,end);//���ٲ���!!!
		return;//�ǵ�return 
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
	//��ɢ�� 
	sort(X+1,X+1+(2*n));
	xcnt=unique(X+1,X+1+(2*n))-(X+1);//ȥ��
	//�Ҷ˵�ƫ��ӳ��  [l,r]-->[X[l],X[r+1]] eg:[1,1]-->[X[1],X[2]]
	//����ʱ,[X[1],X[2]]-->[l,r-1](���ֲ���l��r) 
	////����һһ��Ӧ��Ӧ���Ƕ�Ӧ������㣬����һ��������� 
	build(1,1,xcnt-1);//������ɢ����Ӧ 
	for(i=1;i<cnt;i++){
		int l=lower_bound(X+1,X+1+xcnt,a[i].x_left)-X;
		int r=lower_bound(X+1,X+1+xcnt,a[i].x_right)-X;
		change(1,1,xcnt-1,l,r-1,a[i].mark);
		//(a[i+1].y-a[i].y)����ǿ�� 
		//tree[1].len��ǰ���ܳ��� 
		ans+=1LL*tree[1].len*(a[i+1].y-a[i].y);
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
