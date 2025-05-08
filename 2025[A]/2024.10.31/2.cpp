#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=1000000007;
struct nod{
	double lg;
	int power,num;//Ô­Êý×Önum ¹±Ï×³Ë·½power
}t,r;
deque<nod>q;
int work(int x){
	int ans=0;
	while(x%2==0){
		x/=2;ans++;
	}
	return ans;
}
int getnum(int x){
	while(x%2==0){
		x/=2;
	}
	return x;
}
int T,a[200009],n,i,j,sum,Sum,power,p2[8000009],ans;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;p2[0]=1;
	for(i=1;i<=8000000;i++){
		p2[i]=p2[i-1]*2;
		p2[i]%=P;
	}
	while(T--){
		while(!q.empty())q.pop_back();
		scanf("%lld",&n);Sum=sum=0;power=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++){
			t.lg=log(a[i])/log(2);
			t.lg+=power;
			t.power=work(a[i]);
			t.num=getnum(a[i]);
			while(!q.empty()&&t.lg>=q.back().lg){
				r=q.back();q.pop_back();
				sum+=r.num;sum%=P;t.power+=r.power;
				Sum=(Sum-r.num*p2[r.power]%P+P)%P;
			}
			q.push_back(t);
			Sum=(Sum+t.num*p2[t.power]%P)%P;
			power+=work(a[i]);
			ans=Sum+sum;ans%=P;
			if(i==n)printf("%lld\n",ans);
			else printf("%lld ",ans);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
