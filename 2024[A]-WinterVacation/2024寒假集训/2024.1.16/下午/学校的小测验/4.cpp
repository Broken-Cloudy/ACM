#include<iostream>
#include<cstdio>
using namespace std;
int n,i,a[5009],d=1,h;
long long ans[5009],anss;
const int inf=998244353;
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}ans[1]++;
	for(i=1;i<=n;i++){
		int t=i,k=1;
		while(t+k*a[t]<=n){
			ans[t+k*a[t]]+=ans[i];
			ans[i]%=inf;
			k++;
		}
	}
	for(i=1;i<=n;i++)anss+=ans[i];
	printf("%lld\n",anss%inf);
	fclose(stdin);fclose(stdout);
	return 0;
}
