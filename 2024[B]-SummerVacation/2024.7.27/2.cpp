#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int a,b;
};
nod arr[200009];
struct cmp{
	bool operator()(nod x,nod y){
		return x.a<y.a;
	}
};
priority_queue<nod,vector<nod>,cmp>q;
int T,n,i,k,op,dec,ans;
int shou,mo;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);ans=0;
		for(i=1;i<=n;i++)scanf("%lld",&arr[i].a);
		for(i=1;i<=n;i++)scanf("%lld",&arr[i].b);
		while(!q.empty())q.pop();
		for(i=1;i<=n;i++)q.push(arr[i]);
		while(k>0){
			nod t=q.top();q.pop();
			if(t.a==0)break;
			nod r=q.top();
			op=(t.a-r.a)/t.b+1;
			shou=t.a;mo=t.a-(op-1)*t.b;
			if(op>k){
				shou=t.a;mo=t.a-(k-1)*t.b;
				ans+=(shou+mo)*k/2;
				k=0;
			}
			else{
				t.a=max(0LL,t.a-t.b*op);
				if(t.a>=0)q.push(t);
				ans+=(shou+mo)*op/2;
				k-=op;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
