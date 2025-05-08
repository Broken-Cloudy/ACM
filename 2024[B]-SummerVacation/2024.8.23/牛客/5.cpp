#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,ans,n,m,i,cnt,high;
struct nod{
	int h,x;
};
bool cmp(nod x,nod y){
	return x.x<y.x;
}
nod a[200009];
priority_queue<int,vector<int>,less<int> >q;
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>T;
	while(T--){
		while(!q.empty())q.pop();
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)scanf("%lld",&a[i].h);
		for(i=1;i<=n;i++)scanf("%lld",&a[i].x);
		if(n==1){
			printf("1\n");
			continue;
		}
		sort(a+1,a+1+n,cmp);
		cnt=1;high=a[1].h;
		for(i=2;i<=n;i++){
			if(high+a[i-1].x<a[i].x){
				q.push(cnt);
				cnt=1;
				high=a[i].h;
			}
			else{
				cnt++;
				high=max(a[i].h,high-(a[i].x-a[i-1].x));
			}
			if(i==n)q.push(cnt);
		}
		ans=0;
		while(!q.empty()&&m>0){
			m--;
			int t=q.top();q.pop();
			ans+=t;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
