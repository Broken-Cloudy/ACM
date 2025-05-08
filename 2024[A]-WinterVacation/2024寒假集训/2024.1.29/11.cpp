#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10009],G,r[10009],cnt,i,ans,j,k,used[10009],d[10009],h;
bool vis[10009],f;
void gcd(long long a,long long b){
	if(b==0){
		r[++cnt]=a;
		return;
	}
	gcd(b,a%b);
}
long long workout(long long x){
	return (m-x)*(m/x)/2;
}
void GCD(long long a,long long b){
	if(b==0){
		k=a;
		return;
	}
	GCD(b,a%b);
}
long long Lcm(long long a,long long b){
	GCD(a,b);
	return a*b/k;
}
void dfs(long long Num,long long bh,long long deep,long long k){//bh==0 +;bh==1 -
	if(Num>=m)return;
	if(deep==cnt&&f==1){
		if(bh==0)ans+=workout(Num);
		else ans-=workout(Num);
		return;
	}
	else if(deep==cnt&&f==0)f=1;
	for(int i=k;i<=cnt;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(Num,bh,deep+1,i);//不交叉 
			long long L=Lcm(max(r[i],Num),min(r[i],Num));
			if(L<m){
				used[i]=1;
				dfs(L,!bh,deep+1,i);//交叉 
				used[i]=0;
			}
			vis[i]=0;
		}
	}
}
int main(){
	freopen("11.in","r",stdin);freopen("11.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	//sort(a+1,a+1+n);
	for(i=1;i<=n;i++){
		if(a[i]>=m)a[i]%=m;
		gcd(m,a[i]);
	}
	sort(r+1,r+1+cnt);
	for(i=1;i<=cnt;i++){
		bool f=0;
		for(int j=1;j<=h;j++){
			if(r[i]%d[j]==0){
				f=1;break;
			}
		}
		if(f==0)d[++h]=r[i];
	}
	memcpy(r,d,sizeof(d));
	cnt=h;
	dfs(1,1,0,1);//dfs实现容斥 
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
