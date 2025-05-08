#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,a[1000009],b[1000009],c[2000009],cnt,k,L,R,r,s,ans;
int K,ANS;
int sum1[1000009],sum2[1000009];
int check(int x){
	int k1,k2;
	k1=(sum1[n]-sum1[r-1])-x*(n-r+1);
	k1+=x*(r-1)-sum1[r-1];
	k2=(sum2[m]-sum2[s-1])-x*(m-s+1);
	k2+=x*(s-1)-sum2[s-1];
	return abs(k1-k2);
}
void sanfen(int l,int r){
	int part1=l+(r-l)*1/3;
	int part2=l+(r-l)*2/3;
	if(l+1==r){
		if(check(l)<=check(r))ans=l;
		else ans=r;
		return;
	}
	else if(l+2==r){
		int A=check(l);
		int B=check(l+1);
		int C=check(l+2);
		if(A<=B&&A<=C)ans=l;
		else if(B<=A&&B<=C)ans=l+1;
		else ans=l+2;
		return;
	}
	if(check(part1)<=check(part2))sanfen(l,part2);
	else sanfen(part1,r);
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]),c[++cnt]=a[i];
	for(i=1;i<=m;i++)scanf("%lld",&b[i]),c[++cnt]=b[i];
	sort(a+1,a+1+n);sort(b+1,b+1+m);sort(c+1,c+1+cnt);
	for(i=1;i<=n;i++)sum1[i]=sum1[i-1]+a[i];
	for(i=1;i<=m;i++)sum2[i]=sum2[i-1]+b[i];
	k=unique(c+1,c+1+cnt)-(c+1);
	c[0]=-2000000000LL;c[++k]=2000000000LL;
	r=1;s=1;
	K=-2000000000LL;ANS=check(K);
	for(i=0;i<k;i++){
		L=c[i];R=c[i+1];
		while(a[r]<=c[i]&&r<=n)r++;
		while(b[s]<=c[i]&&s<=m)s++;
		sanfen(L,R);
		if(check(ans)<ANS){
			ANS=check(ans);
			K=ans;
		}
	}
	cout<<K<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
