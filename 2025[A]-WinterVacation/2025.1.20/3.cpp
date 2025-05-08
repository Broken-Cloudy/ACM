#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=998244353LL;
int T,i,j,n,a[200009];
map<int,int>f,g;
queue<int>q;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);f.clear();g.clear();
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		while(!q.empty())q.pop();
		if(a[1]>0){
			f[1]=0;g[1]=1;
			f[0]=0;g[0]=0;
		}
		else{
			f[1]=0;g[1]=1;
			f[0]=1;g[0]=0;
			q.push(0);
		}
		int SUM=0;
		for(i=2;i<=n;i++){
			int GG=g[a[i]],FF=f[a[i]];
			g.clear();
			while(!q.empty()){
				j=q.front();q.pop();
				g[j+1]=f[j];
			}
			f.clear();
			f[a[i]]=GG+FF;
			f[a[i]]%=P;
			q.push(a[i]);	
		}
		for(i=0;i<=n;i++)SUM+=g[i],SUM%=P;
		printf("%lld\n",(f[a[n]]+SUM)%P);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
