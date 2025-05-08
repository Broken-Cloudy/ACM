#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,n,ANS,b[100009],kk,bh[100009],mini;
bool FF;
struct nod{
	int a,b,sum;
}a[100009],t,d;
struct cmp2{
	bool operator()(nod x,nod y){
		return x.sum<y.sum;
	}
};
struct cmp3{
	bool operator()(nod x,nod y){
		return x.a>y.a;
	}
};
bool cmp1(nod x,nod y){
	return x.a>y.a;
}
priority_queue<nod,vector<nod>,cmp2>q1;
priority_queue<nod,vector<nod>,cmp3>q2;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		while(!q1.empty())q1.pop();
		while(!q2.empty())q2.pop();
		scanf("%lld",&n);
		for(i=1;i<=n;i++){
			scanf("%lld%lld",&a[i].a,&a[i].b);
			a[i].sum=a[i].a+a[i].b;
		}
		sort(a+1,a+1+n,cmp1);ANS=a[1].a;mini=a[1].sum;
		t.a=a[1].a;t.b=a[1].b;t.sum=a[1].sum;q2.push(t);
		for(i=2;i<=n;i++){
			ANS=max(ANS,a[i].a+a[i].b);
			t.a=a[i].a;t.b=a[i].b;t.sum=a[i].sum;
			q1.push(t);
		}
		while(!q2.empty()){
			t=q2.top();q2.pop();
			if(t.a>=mini){
				ANS=max(ANS,a[1].a+a[1].b);
				break;
			}
			if(t.sum>=mini){
				mini=t.a;
			}
			while(!q1.empty()){//sum
				d=q1.top();
				if(d.sum<mini){
					break;
				}
				else{
					q1.pop();
					q2.push(d);
				}
			}
		}
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
