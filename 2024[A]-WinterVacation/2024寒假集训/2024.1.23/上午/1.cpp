#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const ll MAXN=5e5+8;
const ll inf=1e17+7;
bool flag=0;
ll n,m,a[MAXN*4],treea[MAXN*4],i,op,x,y,k;//treea[MAXN*4]就是mini[MAXN*4]
ll tag1[MAXN*4];//tag2_min[MAXN*4]
//hismini[MAXN*4]就是以前的treeb[MAXN*4] 
ll tag2_hismin[MAXN*4],hismini[MAXN*4];
void add_tag(ll node,ll start,ll end,ll k){
	//tag2_hismin[node]=min(tag2_hismin[node],tag1[node]+tag2_hismin[node/2]);
	//hismini[node]=min(hismini[node],treea[node]+tag2_hismin[node/2]);
	tag1[node]+=k;
	treea[node]+=k;//当前结点就表示一个区间最小值，只需要加k 
	return;
}
void pushdown(ll node,ll start,ll end){//只需执行一次 
	if(tag1[node]==0)return;//没有标记，不需要考虑
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		ll t=tag1[node];
		add_tag(zuo,start,mid,t);//标记下传(标记并不是去除，而是下传) 
		add_tag(you,mid+1,end,t);//标记下传(标记并不是去除，而是下传)
		tag1[node]=0;//标记清空 
	} 
}
void build_tree(ll node,ll start,ll end){
	if(start==end){
		treea[node]=a[start];
		return;
	}
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		build_tree(zuo,start,mid);
		build_tree(you,mid+1,end);
		treea[node]=min(treea[zuo],treea[you]);//区间最小值 
	}
}
ll mini(ll node,ll start,ll end,ll L,ll R){//返回最小值 
	pushdown(node,start,end);
	if(end<L||start>R)return inf;
	else if(end<=R&&start>=L)return treea[node];
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		ll x=mini(zuo,start,mid,L,R);
		ll y=mini(you,mid+1,end,L,R);
		return min(x,y);
	}
}
ll hism(ll node,ll start,ll end,ll L,ll R){//返回最小值 
	pushdown(node,start,end);
	if(end<L||start>R)return 0;
	else if(end<=R&&start>=L)return hismini[node];
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		ll x=hism(zuo,start,mid,L,R);
		ll y=hism(you,mid+1,end,L,R);
		return min(x,y);
	}
}
void change(ll node,ll start,ll end,ll L,ll R,ll k){
	if(end<L||start>R)return;
	else if(end<=R&&start>=L){
		add_tag(node,start,end,k);
		return;
	}
	else{
		pushdown(node,start,end);
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change(zuo,start,mid,L,R,k);
		change(you,mid+1,end,L,R,k);
		treea[node]=min(treea[zuo],treea[you]);//pushup 
		//hismini[node]=min(hismini[zuo],hismini[you]);
	}
}
ll read(){
	ll a=0;
	bool b=0;
	char c;
	c=getchar();
	if(c=='-'){
		b=1;
		c=getchar();
	}
	while(c!=' '&&c!='\n'&&c!=-1){
		a=a*10+c-48;
		c=getchar();
		if(c=='\n'||c==-1)flag=1;
	}
	if(b==1)return -a;
	else return a;
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	build_tree(1,1,n);
	//memcpy(hismini,treea,sizeof(treea));
	cin>>m;
	getchar();
	for(i=1;i<=m;i++){
		flag=0;
		x=read();y=read();
		x+=1;y+=1;
		if(flag==1){
			if(x>y){
				ll ans1=mini(1,1,n,x,n);
				ll ans2=mini(1,1,n,1,y);
				ll ans=min(ans1,ans2);
				printf("%lld\n",ans);
			}
			else{
				ll ans=mini(1,1,n,x,y);
				printf("%lld\n",ans);
			}
			
		}
		else{
			if(x>y){
				k=read();
				change(1,1,n,1,y,k);
				change(1,1,n,x,n,k);
			}
			else{
				k=read();
				change(1,1,n,x,y,k);
			}
			
		}
		/*else{
			cin>>x>>y;
			//scanf("%lld%lld",&x,&y);
			change(1,1,n,x,y,0);
			ll ans=hism(1,1,n,x,y);
			cout<<ans<<endl;
		}*/
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
