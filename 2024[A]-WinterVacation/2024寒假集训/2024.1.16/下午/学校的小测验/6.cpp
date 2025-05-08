#include<iostream>
#include<cstdio>
using namespace std;
long long n,s,i,a[12][31],ans,wei[12],j;
long long check(){
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i][wei[i]];
	}
	return ans;
}
void dfs(int x){
	if(x==n+1){
		if(check()<=s){
			ans++;
		}
		return;
	}
	for(int i=1;i<=a[x][0];i++){
		wei[x]=i;
		if(check()>s)break;
		dfs(x+1);
	}
	wei[x]=1;
}
int main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>n>>s;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i][1]);
		j=1;
		while(a[i][j]<=s){
			j++;
			a[i][j]=a[i][j-1]*a[i][1];
		}
		a[i][0]=j-1;
	}
	for(i=1;i<=n;i++)wei[i]=1;
	dfs(1);
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
