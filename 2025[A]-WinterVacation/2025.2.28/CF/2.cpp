#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,j,k[109],ans[500009];
bool F;
map<int,int>M;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	for(i=1;i<=500000;i++)M[i*i]=1;
	for(i=1;i<=500000;i++)ans[i]=i;
	for(i=1;i<=500000;i++){
		if(i%2==0){
			if(M[i/2]==1&&M[i+1]==1)k[++k[0]]=i;
		}
		else{
			if(M[i]==1&&M[(i+1)/2]==1)k[++k[0]]=i;
		}
	}
	for(i=1;i<=500000;i++){
		for(j=1;j<=k[0];j++){
			if(i==k[j])swap(ans[i],ans[i+1]);
		}
	}
	cin>>T;
	while(T--){
		scanf("%lld",&n);F=0;
		for(i=1;i<=k[0];i++){
			if(n==k[i]){
				F=1;break;
			}
		}
		if(F==1){
			printf("-1\n");
			continue;
		}
		for(i=1;i<=n;i++){
			if(i==n)printf("%lld\n",ans[i]);
			else printf("%lld ",ans[i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
