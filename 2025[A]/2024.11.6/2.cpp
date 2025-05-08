#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int inf=100000000000000009LL;
const int P=1000000007LL;
int i,n,m,T,a[300009],b[300009],f[300009],F[300009],sum[300009],j,d,l,r,p;
int tree[4000009];
void build(ll node,ll start,ll end){//Ҫ�¸�,�Ƚ��� 
	if(start==end){
		tree[node]=F[start];//��return a[end] 
	}
	else{//node�ǵ�ǰ�������е����� 
		ll mid=(start+end)/2;
		ll zuo=2*node;//ֱ�ӷ��������� 
		ll you=2*node+1;//ֱ�ӷ��������� 
		build(zuo,start,mid);
		build(you,mid+1,end);
		tree[node]=tree[zuo]+tree[you];
	}
}
void change(ll node,ll start,ll end,ll X,ll k){
	if(end<X||start>X)return;//���ٲ���!!!
	else if(start>=X&&end<=X){
		tree[node]=k;
		return;//�ǵ�return 
	} 
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		change(zuo,start,mid,X,k);
		change(you,mid+1,end,X,k);
		tree[node]=(tree[zuo]+tree[you])%P;
	}
}
//L��Ŀ���� R��Ŀ����[L,R]
//start�ǵ�ǰ���ڲ�ѯ����ʼ�㣬end�ǵ�ǰ���ڲ�ѯ�Ľ�����
//��ǰ���ڲ�ѯ[start,end] 
ll Sum(ll node,ll start,ll end,ll L,ll R){
	if(end<L||start>R)return 0;//���ٲ���!!!
	else if(start>=L&&end<=R)return tree[node]; 
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=Sum(zuo,start,mid,L,R);
		ll y=Sum(you,mid+1,end,L,R);
		return (x+y)%P;
	}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)f[i]=inf,F[i]=0;
		F[0]=1;build(1,0,n);
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
		for(i=1;i<=m;i++)scanf("%lld",&b[i]);
		for(i=1;i<=m;i++){//b
			for(j=1;j<=n;j++){//a
				l=lower_bound(sum,sum+1+n,sum[j]-b[i])-sum;
				if(f[l]+(m-i)<f[j]){
					f[j]=f[l]+(m-i);
					l=lower_bound(sum,sum+1+n,sum[j]-b[i])-sum;
					r=upper_bound(f+l,f+j,f[l])-(f+1);
					change(1,0,n,j,Sum(1,0,n,l,r));
				}
				else if(f[l]+(m-i)==f[j]){
					r=upper_bound(f+l,f+j,f[l])-(f+1);
					change(1,0,n,j,Sum(1,0,n,l,r)+Sum(1,0,n,j,j));
				}
			}
		}
		if(f[n]==inf)printf("-1\n");
		else printf("%lld %lld\n",f[n],Sum(1,0,n,n,n)%P);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
