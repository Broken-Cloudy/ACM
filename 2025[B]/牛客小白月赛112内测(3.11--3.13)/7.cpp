#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int MOD1=1000000009;
const int MOD2=1000000007;
struct nod{
	int level,bh;
}t;
deque<nod>q;
int n,i,j,k,ANS,Hashb[100009],Hashc[100009],p2[100009],p3[100009],ans,Lev,anss;
char c[100009],b[100009];
int tree[1600009],tag[1600009],HashB[100009],HashC[100009];
void add_tag(ll node,ll start,ll end,ll k){//���˱�� 
	tag[node]=k;
	tree[node]=(end-start+1)*k;//�Ȱѱ�������ˣ�����Ĳ����Ȳ��ӣ������� 
	return;
}
void pushdown(ll node,ll start,ll end){//ֻ��ִ��һ�� 
	if(tag[node]==-1)return;//û�б�ǣ�����Ҫ����
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		ll t=tag[node];
		add_tag(zuo,start,mid,t);//����´�(��ǲ�����ȥ���������´�) 
		add_tag(you,mid+1,end,t);//����´�(��ǲ�����ȥ���������´�) 
		tag[node]=-1;//������ 
	} 
}
void change(ll node,ll start,ll end,ll L,ll R,ll k){
	if(end<L||start>R)return;//���ٲ���!!!
	else if(start>=L&&end<=R){
		add_tag(node,start,end,k);
		return;//�ǵ�return 
	} 
	else{
		pushdown(node,start,end);//��ֵ��ʱ��ҲҪ�´���ϸ����������ܻ�Ӱ���� 
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change(zuo,start,mid,L,R,k);
		change(you,mid+1,end,L,R,k);
		tree[node]=tree[zuo]+tree[you];
	}
}
//L��Ŀ���� R��Ŀ����[L,R]
//start�ǵ�ǰ���ڲ�ѯ����ʼ�㣬end�ǵ�ǰ���ڲ�ѯ�Ľ�����
//��ǰ���ڲ�ѯ[start,end] 
ll S(ll node,ll start,ll end,ll X){
	pushdown(node,start,end);//NlogN�� 
	if(end<X||start>X)return 0LL;//���ٲ���!!!
	else if(start>=X&&end<=X)return tree[node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=S(zuo,start,mid,X);
		ll y=S(you,mid+1,end,X);
		return x+y;
	}
}
bool check(int x,int L,int R){
	int ans1,ans2,l,r,ans3,ans4;
	l=L-x+1;r=L;//c
	ans1=(Hashc[l]-Hashc[r+1]*p2[x]%MOD1+MOD1)%MOD1;
	ans3=(HashC[l]-HashC[r+1]*p3[x]%MOD2+MOD2)%MOD2;
	l=R;r=R+x-1;//b
	ans2=(Hashb[r]-Hashb[l-1]*p2[x]%MOD1+MOD1)%MOD1;
	ans4=(HashB[r]-HashB[l-1]*p3[x]%MOD2+MOD2)%MOD2;
	if(ans1==ans2&&ans3==ans4)return 1;
	else return 0;
}
void dfs(int l,int r,int L,int R){
	if(l==r){
		ans=l;
		return;
	}
	else if(l==r-1){
		if(check(r,L,R))ans=r;
		else ans=l;
		return;
	}
	else{
		int mid=(l+r)/2;
		if(check(mid,L,R))dfs(mid,r,L,R);
		else dfs(l,mid,L,R);
		return;
	}
}
signed main(){
	freopen("7.in","r",stdin);freopen("7.out","w",stdout);
	cin>>n;getchar();
	for(i=1;i<=16*n;i++)tag[i]=-1;
	for(i=1;i<=n;i++)c[i]=getchar();
	p2[0]=1;p3[0]=1;
	for(i=1;i<=n;i++){
		p2[i]=p2[i-1]*2;p3[i]=p3[i-1]*2;
		p2[i]%=MOD1;p3[i]%=MOD2;
	}
	for(i=1;i<=n;i++){
		if(c[i]=='('){
			b[i]=')';
		}
		else{
			b[i]='(';
		}
	}
	//Hashb��,Hashc�� 
	for(i=1;i<=n;i++){
		if(b[i]=='(')Hashb[i]=Hashb[i-1]*2+1;
		else Hashb[i]=Hashb[i-1]*2;
		Hashb[i]%=MOD1;
		if(b[i]=='(')HashB[i]=HashB[i-1]*2+1;
		else HashB[i]=HashB[i-1]*2;
		HashB[i]%=MOD2;
	}
	for(i=n;i>=1;i--){
		if(c[i]=='(')Hashc[i]=Hashc[i+1]*2+1;
		else Hashc[i]=Hashc[i+1]*2;
		Hashc[i]%=MOD1;
		if(c[i]=='(')HashC[i]=HashC[i+1]*2+1;
		else HashC[i]=HashC[i+1]*2;
		HashC[i]%=MOD2;
	}
	t.level=0;t.bh=0;q.push_back(t);
	for(i=1;i<n;i++){
		if(c[i]=='('){
			Lev++;
			t.level=Lev;t.bh=i;
			q.push_back(t);
			anss=S(1,1,n,i-1);
			change(1,1,n,i,i,anss+1);
		}
		else{
			k=i;t.bh=i-1;
			while(!q.empty()){
				t=q.back();
				if(t.level==0)break;
				if(t.level==Lev){
					Lev--;
					break;
				}
				else{
					q.pop_back();
					k=t.bh;
				}
			}
			anss=S(1,1,n,t.bh);
			change(1,1,n,k,i,anss);
		}
		if(c[i]==b[i+1]){
			dfs(1,min(i,n-i),i,i+1);
			ANS+=(S(1,1,n,i)-S(1,1,n,i-ans));//i-ans---i
		}
	}
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
