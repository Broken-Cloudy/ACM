#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX_N=1e5+9;
struct nod{
	int xj,j,time;
}t;
struct cmp{
	bool operator()(nod x,nod y){
		return x.time>y.time;
	}
};
int T,i,n,m,a[MAX_N],b[MAX_N],vis[MAX_N],xj[MAX_N],j[MAX_N],SUM,ans;
priority_queue<nod,vector<nod>,cmp>q;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		vector<int>kk[MAX_N];
		while(!q.empty())q.pop();ans=0;SUM=0;
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			b[i]=a[i];vis[i]=0;
		}
		for(i=1;i<=m;i++){
			scanf("%lld%lld",&xj[i],&j[i]);
			t.xj=xj[i];t.j=j[i];t.time=i;
			q.push(t);vis[j[i]]++;
		}
		for(i=1;i<=n;i++){
			if(!vis[i]){
				SUM+=a[i];
				b[i]=0;
			}
		}
		for(i=1;i<=m;i++){
			int need=xj[i]-ans;
			while(!q.empty()&&need>0){
				t=q.top();q.pop();
				if(need>b[t.j]){
					need-=b[t.j];
					b[t.j]=0;
					kk[t.j].push_back(t.time);
				}
				else{
					b[t.j]-=need;
					q.push(t);
					need=0;
				}
			}
			if(need>0){
				if(need>SUM){
					ans=xj[i]-need+SUM;
					SUM=0;
					break;
				}
				else{
					SUM-=need;
					ans=xj[i];
				}
			}
			else ans=xj[i];
			if(vis[j[i]]==1){
				b[j[i]]=0;
				SUM+=a[j[i]];
			}
			else{
				b[j[i]]=a[j[i]];
				while(!kk[j[i]].empty()){
					int tt=*kk[j[i]].begin();
					kk[j[i]].erase(kk[j[i]].begin());
					if(tt>i){
						t.xj=114514LL;
						t.j=j[i];
						t.time=tt;
						q.push(t);
						break;
					}
				}
			}
			vis[j[i]]--;
		}
		for(i=1;i<=n;i++){
			if(b[i])ans+=b[i];
		}
		ans+=SUM;
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
