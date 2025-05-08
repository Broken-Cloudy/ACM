#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,j,a[200009],m,k,w,p[200009],ans,cnt;
bool cmp(int a,int b){
	return a>b;
}
int f(int i,int j,int n,int m,int k) {
	int row=min(i+1,k)+min(n-i,k)-k;
	int col=min(j+1,k)+min(m-j,k)-k;
	return row*col;
}
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&k);
		scanf("%lld",&w);ans=0;cnt=0;
		for(i=1;i<=w;i++)scanf("%lld",&a[i]);
		sort(a+1,a+1+w,cmp);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				p[++cnt]=f(i,j,n,m,k);
			}
		}
		sort(p+1,p+1+cnt,cmp);
		for(i=1;i<=w;i++)ans+=p[i]*a[i];
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
