#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[100009],i,ANS,ans,fu,pz;
bool check(int x,int i){
	int d=x-a[i];
	if(d>i-1){
		return false;
	}
	else return true;
}
int work(int x,int l,int r){//1--fu
	if(r<l)return 0;
	if(l==r){
		if(r==fu&&check(x,fu)==0)return 0;
		else return fu-l+1;
	}
	else if(l+1==r){
		if(r==fu&&check(x,fu)==0)return 0;
		else if(check(x,l)==0){
			return fu-r+1;
		}
		else return fu-l+1;
	}
	int mid=(l+r)/2;
	if(check(x,mid)){
		return work(x,l,mid);
	}
	else return work(x,mid,r);
}
bool check2(int x,int i){
	int d=a[i]-x;
	if(d>n-i){
		return false;
	}
	else return true;
}
int work2(int x,int l,int r){//1--fu
	if(r<l)return 0;
	if(l==r){
		if(l==pz&&check2(x,pz)==0)return 0;
		else return l-pz+1;
	}
	else if(l+1==r){
		if(l==pz&&check2(x,pz)==0)return 0;
		else if(check2(x,r)==0){
			return l-pz+1;
		}
		else return r-pz+1;
	}
	int mid=(l+r)/2;
	if(check2(x,mid)){
		return work2(x,mid,r);
	}
	else return work2(x,l,mid);
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		pz=100005;fu=100005;ANS=0;
		scanf("%lld",&n);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(a[i]>=0&&fu==100005&&pz==100005)fu=i-1,pz=i;
		}
		if(fu==100005)fu=n;//全是负数 
		ans=0;ans+=work(0,1,fu);ANS=max(ANS,ans);//0
		for(i=pz;i<=n;i++){
			if(n-i>=a[i]){//可以移动 
				ans=i-pz+1;
				ans+=work(a[i],1,fu);
				ANS=max(ANS,ans);
			}
		}
		for(i=fu;i>=1;i--){
			if(i-1>=0-a[i]){//可以移动 
				ans=fu-i+1;
				ans+=work2(a[i],pz,n);
				ANS=max(ANS,ans);
			}
		}
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
