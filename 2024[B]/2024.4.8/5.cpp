#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100009],b[100009],i,n,q,k,Sum[100009],SUM,x,ans,t;
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		Sum[i]=Sum[i-1]+a[i];
	}
	for(i=1;i<=n;i++){
		scanf("%lld",&b[i]);
	}
	while(q){
		priority_queue<int,vector<int>,less<int> >d;
		cin>>x;SUM=0;
		for(i=1;i<=x;i++){
			SUM+=b[i];
			d.push(b[i]);
		}
		ans=SUM+Sum[x];
		for(i=x+1;i<=n;i++){
			t=d.top();
			if(b[i]<=t){
				d.pop();
				d.push(b[i]);
				SUM=SUM+b[i]-t;
			}
			ans=min(ans,SUM+Sum[i]);
		}
		cout<<ans<<endl;
		q--;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
