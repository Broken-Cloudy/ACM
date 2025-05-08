#include<bits/stdc++.h>
#define int long long
using namespace std;
int N,i,k,j,f[10009],y,x,T,bh[10009],ans,anss;
map<int,int>M;
int find(int x){
	if(f[x]==x)return x;
	else{
		f[x]=find(f[x]);
		return f[x];
	}
}
signed main(){
	freopen("128.in","r",stdin);freopen("128.out","w",stdout);
	cin>>N;
	for(i=1;i<=10000;i++)f[i]=i;
	for(i=1;i<=N;i++){
		scanf("%lld",&k);scanf("%lld",&x);bh[x]=1;
		for(j=2;j<=k;j++){
			scanf("%lld",&y);bh[y]=1;
			if(find(x)!=find(y)){
				f[find(x)]=find(y);
			}
		}
	}
	for(i=1;i<=10000;i++){
		if(bh[i]==1){
			ans++;
			if(M[find(i)]==0){
				anss++;
				M[find(i)]=1;
			}
		}
	}
	printf("%lld %lld\n",ans,anss);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&x,&y);
		if(find(x)==find(y))printf("Y\n");
		else printf("N\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
