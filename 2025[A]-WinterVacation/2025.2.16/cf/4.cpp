#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,q,i,a[200009],ans,ANS[200009],k1,k2,SSS[200009];
struct nod{
	int bh,val;
	int ch;
}x,t;
struct cmp{
	bool operator()(nod x,nod y){
		return x.val>y.val;
	}
};
deque<nod>d;
priority_queue<nod,vector<nod>,cmp>Q;
int gbits(int x){
	int cnt=1;
	while(x>1){
		x/=2;
		cnt++;
	}
	return cnt;
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		while(!Q.empty())Q.pop();
		while(!d.empty())d.pop_back();
		scanf("%lld%lld",&n,&q);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(i=1;i<=q;i++){
			scanf("%lld",&x.val);
			x.bh=i;Q.push(x);x.ch=0;
		}
		ans=0;SSS[n+1]=0;
		for(i=n;i>=1;i--)SSS[i]=SSS[i+1]^a[i];
		for(i=n;i>=1;i--){
			k1=gbits(a[i]);
			while(!Q.empty()){
				t=Q.top();Q.pop();
				k2=gbits(t.val^(SSS[i+1]^SSS[t.ch]));
				if(k2<k1){
					ANS[t.bh]=ans;
				}
				else if(k1==k2){
					t.val^=(SSS[i+1]^SSS[t.ch]);
					if(t.val>=a[i]){
						t.val^=SSS[i+1];
						t.ch=i;
						t.val^=SSS[t.ch];
						d.push_back(t);
					}
					else{
						ANS[t.bh]=ans;
					}
				}
				else{
					Q.push(t);
					break;
				}
			}
			while(!d.empty()){
				t=d.back();d.pop_back();
				Q.push(t);
			}
			ans++;
		}
		while(!Q.empty()){
			t=Q.top();Q.pop();
			ANS[t.bh]=ans;
		}
		for(i=1;i<=q;i++){
			if(i==q)printf("%lld\n",ANS[i]);
			else printf("%lld ",ANS[i]);
		}
	}
	fclose(stdin);fclose(stdout);
}
