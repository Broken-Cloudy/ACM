#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
int T,n,l,r,k,x,i,X[200009],xcnt,ans;
int d[200009];
int tag[1600009],tmin[1600009],tmax[1600009];
struct scanline{
	int l,r,k;
};
bool cmp(scanline x,scanline y){
	return x.k<y.k;
}
scanline a[200009];
void build(ll node,ll start,ll end){//Ҫ�¸�,�Ƚ��� 
	if(start==end){
		tmin[node]=d[start];tmax[node]=d[start];
	}
	else{//node�ǵ�ǰ�������е����� 
		ll mid=(start+end)/2;
		ll zuo=2*node;//ֱ�ӷ��������� 
		ll you=2*node+1;//ֱ�ӷ��������� 
		build(zuo,start,mid);
		build(you,mid+1,end);
		tmin[node]=min(tmin[zuo],tmin[you]);
		tmax[node]=max(tmax[zuo],tmax[you]);
	}
}
void add_tag(ll node,ll start,ll end,ll k){//���˱�� 
	tag[node]+=k;
	tmin[node]+=k;//�Ȱѱ�������ˣ�����Ĳ����Ȳ��ӣ������� 
	tmax[node]+=k;
	return;
}
void pushdown(ll node,ll start,ll end){//ֻ��ִ��һ�� 
	if(tag[node]==0)return;//û�б�ǣ�����Ҫ����
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		ll t=tag[node];
		add_tag(zuo,start,mid,t);//����´�(��ǲ�����ȥ���������´�) 
		add_tag(you,mid+1,end,t);//����´�(��ǲ�����ȥ���������´�) 
		tag[node]=0;//������ 
	} 
}
void change(ll node,ll start,ll end,ll L,ll R,ll k){
	if(end<L||start>R)return;//���ٲ���!!!
	else if(start>=L&&end<=R&&tmin[node]>=k){
		add_tag(node,start,end,k);
		return;//�ǵ�return 
	} 
	else if(start>=L&&end<=R&&tmax[node]<k){
		return;//�ǵ�return 
	}
	else{
		pushdown(node,start,end);//��ֵ��ʱ��ҲҪ�´���ϸ����������ܻ�Ӱ���� 
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change(zuo,start,mid,L,R,k);
		change(you,mid+1,end,L,R,k);
		tmin[node]=min(tmin[zuo],tmin[you]);
		tmax[node]=max(tmax[zuo],tmax[you]);
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&x);
		for(i=1;i<=n;i++){
			scanf("%lld%lld%lld",&l,&r,&k);
			X[2*i-1]=l;X[2*i]=r;
			a[i].l=l;a[i].r=r;a[i].k=k;
		}
		sort(X+1,X+1+(2*n));
		xcnt=unique(X+1,X+1+(2*n))-(X+1);//ȥ��
		for(i=1;i<=xcnt-1;i++)d[i]=x;
		build(1,1,xcnt-1);
		sort(a+1,a+1+n,cmp);
		for(i=1;i<=n;i++){
			l=lower_bound(X+1,X+1+xcnt,a[i].l)-X;
			r=lower_bound(X+1,X+1+xcnt,a[i].r)-X;
			change(1,1,xcnt-1,l,r-1,a[i].k);
		}
		printf("%lld\n",tmax[1]);
		for(i=1;i<=8*xcnt;i++){
			tag[i]=0;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
