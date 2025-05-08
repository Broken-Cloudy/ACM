#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int bh,val;
}t;
struct cmp{
	bool operator()(nod x,nod y){
		return x.val<y.val;
	}
};
priority_queue<nod,vector<nod>,cmp>q;
bool cmp(nod x,nod y){
	return x.val<y.val;
}
int T,n,k,a[300009],i,b[300009],ans,le[300009],ri[600009];
int vis[600009],cnt,L[600009],R[600009],si;
char c[300009];
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);getchar();
		for(i=1;i<=n;i++)c[i]=getchar();
		ans=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(c[i]=='B'){
				ans+=a[i];
				a[i]=-a[i];
			}
		}
		if(k==0){
			printf("%lld\n",ans);
			continue;
		}
		b[0]=0;b[++b[0]]=a[1];
		for(i=2;i<=n;i++){
			if(c[i]==c[i-1])b[b[0]]+=a[i];
			else b[++b[0]]=a[i];
		}
		while(!q.empty())q.pop();si=0;
		for(i=1;i<=b[0];i++){
			if(b[i]<0){
				t.bh=i;t.val=b[i];
				le[i]=i-2;L[i]=b[i-1];
				ri[i]=i+2;R[i]=b[i+1];
				if(le[i]<1)le[i]=-1,L[i]=999999999LL;
				if(ri[i]>b[0])ri[i]=-1,R[i]=999999999LL;
				q.push(t);si++;
			}
		}
		for(i=1;i<=2*n;i++)vis[i]=0;
		cnt=b[0];
		while(si>k){
			t=q.top();q.pop();si--;
			if(vis[t.bh]==1)continue;
			if(le[t.bh]==-1){
				if(t.val+R[t.bh]<0){
					vis[ri[t.bh]]=1;vis[t.bh]=1;
					cnt++;
					le[cnt]=-1;ri[cnt]=ri[ri[t.bh]];
					L[cnt]=L[t.bh];R[cnt]=R[ri[t.bh]];
					t.bh=cnt;
					q.push(t);
				}
				else vis[t.bh]=1;
			}
			else if(ri[t.bh]==-1){
				
			}
			else{
				
			}
		}
		while(!q.empty()){
			t=q.top();q.pop();
			if(vis[t.bh]==1)continue;
			ans+=t.val;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
