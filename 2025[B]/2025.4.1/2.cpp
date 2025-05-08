#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int T,i,j,k,a[200009],b[200009],n,f[200009],aa,bb,cc,dd;
int tree1[1600009],tree2[1600009];
void build1(ll node,ll start,ll end){//amax
	if(start==end){
		tree1[node]=a[start];
	}
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		build1(zuo,start,mid);
		build1(you,mid+1,end);
		tree1[node]=max(tree1[zuo],tree1[you]);
	}
}
void build2(ll node,ll start,ll end){//bmin
	if(start==end){
		tree2[node]=b[start];
	}
	else{
		ll mid=(start+end)/2;
		ll zuo=node*2;
		ll you=node*2+1;
		build2(zuo,start,mid);
		build2(you,mid+1,end);
		tree2[node]=min(tree2[zuo],tree2[you]);
	}
}
ll sum1(ll node,ll start,ll end,ll L,ll R){//max
	if(end<L||start>R)return -1;
	else if(start>=L&&end<=R)return tree1[node];
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=sum1(zuo,start,mid,L,R);
		ll y=sum1(you,mid+1,end,L,R);
		return max(x,y);
	}
}
ll sum2(ll node,ll start,ll end,ll L,ll R){//max
	if(end<L||start>R)return 1000000000000000001LL;
	else if(start>=L&&end<=R)return tree2[node];
	else{
		ll mid=(start+end)/2;
		ll zuo=2*node;
		ll you=2*node+1;
		ll x=sum2(zuo,start,mid,L,R);
		ll y=sum2(you,mid+1,end,L,R);
		return min(x,y);
	}
}
int check(int x,int y,int kk){
	int anss=0;
	while(x>kk){
		anss++;
		if(1000000000000000001LL/y<=kk)kk=1000000000000000001LL;
		else kk*=y;
	}
	return anss;
}
int pOw(int a,int p){
	int anss=1LL;
	if(p==0)return 1LL;
	else{
		while(p>1){
			if(p%2==1){
				p--;
				anss*=a;
			}
			else{
				p/=2;
				a=a*a;
			}
		}
		anss*=a;
		return anss;
	}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++)f[i]=1000000000000000001LL;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++)scanf("%lld",&b[i]);
		build1(1,1,n);build2(1,1,n);
		for(i=1;i<=n;i++){//200000
			for(j=i;j>=max(1LL,i-61);j--){//60++
				f[i]=min(f[i],f[j-1]+check(sum1(1,1,n,j,i),sum2(1,1,n,j,i),1LL));
				for(k=j+1;k<=i;k++){//500
					aa=sum2(1,1,n,j,k-1);bb=sum2(1,1,n,k,i);
					if(aa>=bb){
						cc=check(sum1(1,1,n,k,i),bb,1LL);
						dd=sum1(1,1,n,j,k-1);
						f[i]=min(f[i],f[j-1]+check(dd,aa,pOw(bb,cc))+cc);
					}
					else break;
				}
			}
		}
		printf("%lld\n",f[n]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
