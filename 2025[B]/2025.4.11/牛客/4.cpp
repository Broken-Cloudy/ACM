#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,k,a[100009],ci,now,maxx,f[100009],g[100009],ANS,j;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	while(k>=ci){
		k-=ci;
		ci++;k++;
	}
	now=maxx=0;
	for(i=1;i<=n;i++){
		now+=a[i];
		f[i]=max(maxx,now);
		maxx=max(f[i],now);
	}
	now=maxx=0;
	for(i=n,j=1;i>=1;i--,j++){
		now+=a[i];
		g[j]=max(maxx,now);
		maxx=max(g[j],now);
	}
	for(i=0;i<=min(ci,n);i++){
		ANS=max(ANS,f[i]+g[min(ci,n)-i]);
	}
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
