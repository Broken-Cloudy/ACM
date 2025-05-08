#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,len,ans,a[100009],n,f[21][100009],P2[100009],kk,p,q,x,y;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	kk=2;P2[1]=0;//P2向下取整 
	for(i=2;i<=100000;i++){//优化log2到O(1) 
		if(i>=kk){
			P2[i]=P2[i-1]+1;
			kk*=2;
		}
		else P2[i]=P2[i-1];
	}
	cin>>n>>q;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=1;i<=n;i++)f[0][i]=a[i];
	for(p=1;p<=P2[n];p++){
		len=(1LL<<p);
		for(i=1;i<=n-len+1;i++){
			f[p][i]=max(f[p-1][i],f[p-1][i+(1LL<<(p-1))]);
		}
	}
	while(q--){
		scanf("%lld%lld",&x,&y);
		p=P2[y-x+1];
		ans=max(f[p][x],f[p][y-(1LL<<p)+1]);
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
