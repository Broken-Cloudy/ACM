#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[200009],i,b[200009],ha[200009],sum,SUM[200009];
int start;
bool ff=0;
queue<int>q;
priority_queue<int,vector<int> >qq;
int change(int x){
	int ans=a[x];
	while(!qq.empty())qq.pop();
	for(i=x;i<=n;i++){
		if(ha[a[i]]==0){
			ha[a[i]]++;
			q.push(a[i]);
		}
		else{
			ha[a[i]]++;
		}
		if(ha[a[i]]>=2){
			qq.push(a[i]);
		}
		if(!qq.empty()){
			int tt=qq.top();
			b[i]=tt;
		}
		else b[i]=0;
	}
	bool f=0;
	for(i=x+1;i<=n;i++){//check
		if(b[i]!=a[i-1]){
			f=1;
			break;
		}
	}
	if(f==0){
		SUM[x-1]=0;ans=0;
		for(i=x;i<=n;i++){
			SUM[i]=SUM[i-1]+a[i];
		}
		for(i=x;i<=n;i++){
			ans+=SUM[i];
		}
		while(!q.empty()){
			int t=q.front();
			ha[t]=0;
			q.pop();
		}
		ff=1;
		return ans;
	}
	for(i=x+1;i<=n;i++){
		ans+=a[i];
		a[i]=b[i];
		b[i]=0;
	}
	a[x]=0;
	while(!q.empty()){
		int t=q.front();
		ha[t]=0;
		q.pop();
	}
	return ans;
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld",&n);
		start=1;sum=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		ff=0;
		while(ff==0){
			sum+=change(start);
			start++;
		}
		printf("%lld\n",sum);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

