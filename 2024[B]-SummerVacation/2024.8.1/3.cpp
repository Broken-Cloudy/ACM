#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int a,b;
};
struct cmp{
	bool operator()(nod x,nod y){
		return x.a<y.a;
	}
};
priority_queue<nod,vector<nod>,cmp>q;
nod a[200009];
int T,n,i,maxx,k,p,ANS,op,shou,mo;
int check(int x){
	int i,kk=0;
	for(i=1;i<=n;i++){
		kk+=max(0LL,(a[i].a-x+(a[i].b-1))/a[i].b);
	}
	return kk;
}
void b_s(int l,int r){
	if(l==r){
		p=l;
		return;
	}
	int mid=(l+r)/2;
	if(check(mid)>k){
		b_s(mid+1,r);
	}
	else b_s(l,mid);
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);maxx=0;
		while(!q.empty())q.pop();
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i].a);
			maxx=max(maxx,a[i].a);
		}
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i].b);
		}
		b_s(0,maxx);ANS=0;
		for(i=1;i<=n;i++){
			int op=(a[i].a-p+(a[i].b-1))/a[i].b;
			int shou=a[i].a;
			int wei=shou-(op-1)*a[i].b;
			if(op<=0)continue;
			if(op>k){
				a[i].a=max(0LL,shou-k*a[i].b);
				wei=shou-(k-1)*a[i].b;
				ANS+=(shou+wei)*k/2;
				if(wei<0)ANS+=(-wei);
				k=0;
			}
			else{
				a[i].a=max(0LL,shou-op*a[i].b);
				ANS+=(shou+wei)*op/2;
				if(wei<0)ANS+=(-wei);
				k-=op;
			}
		}
		for(i=1;i<=n;i++)q.push(a[i]);
		while(k>0){
			nod t=q.top();q.pop();
			if(t.a==0)break;
			nod r=q.top();
			op=(t.a-r.a)/t.b+1;
			shou=t.a;mo=t.a-(op-1)*t.b;
			if(op>k){
				shou=t.a;mo=t.a-(k-1)*t.b;
				ANS+=(shou+mo)*k/2;
				k=0;
			}
			else{
				t.a=max(0LL,t.a-t.b*op);
				q.push(t);
				ANS+=(shou+mo)*op/2;
				k-=op;
			}
		}
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
