#include<bits/stdc++.h>
#define int long long
using namespace std;
int N,i,j,f[1009],n,k,a[1009][1009],x,vis[1009],ans[1009];
int find(int x){
	if(f[x]==x)return x;
	else{
		f[x]=find(f[x]);
		return f[x];
	}
}
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("159.in","r",stdin);freopen("159.out","w",stdout);
	cin>>N;
	for(i=1;i<=N;i++)f[i]=i;
	for(i=1;i<=N;i++){
		scanf("%lld:",&n);
		for(j=1;j<=n;j++){
			scanf("%lld",&x);
			for(k=1;k<=a[x][0];k++){
				if(find(a[x][k])!=find(i)){
					f[find(a[x][k])]=find(i);
				}
			}
			a[x][++a[x][0]]=i;
		}
	}
	for(i=1;i<=N;i++){
		if(vis[find(i)]==0){
			ans[0]++;
			vis[find(i)]=ans[0];
			ans[ans[0]]=1;
		}
		else{
			ans[vis[find(i)]]++;
		}
	}
	sort(ans+1,ans+1+ans[0],cmp);
	printf("%lld\n",ans[0]);
	for(i=1;i<=ans[0];i++){
		if(i==ans[0])printf("%lld\n",ans[i]);
		else printf("%lld ",ans[i]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
