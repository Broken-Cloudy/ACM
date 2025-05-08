#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int val,zt;
}t,r;
map<int,map<int,int> >M;
map<int,int>Vis;
queue<nod>q;
int T,i,n,a[300009],ans;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ans=0;
		M.clear();Vis.clear();
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++){
			if(a[i]>(n-i+1)){
				M[(a[i]-(n-i+1))][++M[(a[i]-(n-i+1))][0]]=(i-1);
			}
			else if(a[i]==(n-i+1)){
				t.zt=0;t.val=(i-1);
				q.push(t);
			}
		}
		while(!q.empty()){
			t=q.front();q.pop();
			ans=max(ans,t.val+t.zt);
			if(Vis[t.zt+t.val]!=1){
				Vis[t.zt+t.val]=1;
				for(i=1;i<=M[t.zt+t.val][0];i++){
					r.zt=t.zt+t.val;r.val=M[t.zt+t.val][i];
					q.push(r);
				}
			}
		}
		printf("%lld\n",ans+n);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
