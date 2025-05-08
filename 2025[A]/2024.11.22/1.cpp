#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX_NM=2e5+9;
int i,j,n,m,a[MAX_NM],f[MAX_NM],T,b[MAX_NM],c[MAX_NM];
vector<set<int>>ans(MAX_NM);
map<int,int>M;
int find(int x){
	if(f[x]==x)return x;
	else{
		f[x]=find(f[x]);
		return f[x];
	}
}
signed main(){
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		f[i]=i;
	}
	for(T=1;T<=m;T++){
		scanf("%lld%lld",&i,&j);
		if(find(i)!=find(j)){
			f[find(i)]=find(j);
		}
	}
	for(i=1;i<=n;i++){
		f[i]=find(i);
		ans[f[i]].insert(i);
	}
	for(i=1;i<=n;i++){
		b[0]=0;M.clear();
		for(auto t:ans[i]){
			b[++b[0]]=t;
			c[t]++;
		}
		for(j=1;j<=b[0];j++){
			
		}
	}
	return 0;
}
