#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=1e9+7;
int T,i,n,a[200009],vis[400009],ANS,zero,SS[200009],j,k,tt;
map<int,int>M;
void add(int x){
	if(M[x]==0){
		vis[0]++;
		M[x]=vis[0];
	}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);vis[0]=0;zero=1;//0的数量 
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++)SS[i]=SS[i-1]^a[i];//累计影响值 
		for(i=1;i<=n;i++){
			j=a[i]^SS[i-1];//last
			k=a[i]^SS[i];//now
			if(M[j]==0){
				if(zero>0){
					add(k);
					vis[vis[0]]=(zero*3LL)%INF;
					zero=0;
				}
			}
			else{
				tt=vis[M[j]];vis[M[j]]=0;M[j]=0;tt%=INF;
				add(k);
				vis[M[k]]+=(tt*2LL+zero*3LL)%INF;
				vis[M[k]]%=INF;
				zero=tt;
			}
		}
		ANS=zero;
		for(i=1;i<=vis[0];i++){
			ANS+=vis[i];
			ANS%=INF;
			vis[i]=0;
		}
		printf("%lld\n",ANS);M.clear();
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
