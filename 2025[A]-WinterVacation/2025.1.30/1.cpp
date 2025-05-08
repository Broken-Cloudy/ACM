#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,m,k,a[100009],b[19],j,ans,w[100009][12];
int dp[1027],num[1027];
int p[12],C;
struct nod{
	int cha,bh,c;
}t;
struct cmp{
	bool operator()(nod x,nod y){
		return x.cha<y.cha;
	}
};
priority_queue<nod,vector<nod>,cmp>q;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&m,&k);ans=0;
		while(!q.empty())q.pop();
		for(i=1;i<=n;i++)scanf("%lld",&a[i]),ans+=a[i];
		for(i=1;i<=m;i++)scanf("%lld",&b[i]);
		for(i=0;i<=(1LL<<m)-1LL;i++){
			dp[i]=(1LL<<36LL)-1LL;
			num[i]=0;
		}
		for(i=0;i<=(1LL<<m)-1LL;i++){//1023
			for(j=1;j<=m;j++){//10
				if(i&(1LL<<(j-1))){
					num[i]++;
					dp[i]=dp[i]&b[j];
				}
			}
		}
		for(i=1;i<=n;i++){//100000
			for(j=0;j<=10;j++)w[i][j]=0;
			for(j=0;j<=(1LL<<m)-1LL;j++){//1024
				w[i][num[j]]=max(w[i][num[j]],(a[i]-(a[i]&dp[j])));
			}
		}
		for(i=1;i<=n;i++){
			t.cha=w[i][1];t.bh=i;t.c=1;q.push(t);
		}
		while((k--)&&(!q.empty())){
			t=q.top();q.pop();
			i=t.bh;C=t.c;C++;
			ans-=t.cha;
			t.cha=w[i][C]-w[i][C-1];t.bh=i;t.c=C;
			if(C<=m)q.push(t);
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
