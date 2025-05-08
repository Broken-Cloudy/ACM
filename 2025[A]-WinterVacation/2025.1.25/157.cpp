#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,a[10009],sum,chose[10009],ans[10009],f[109],num[109];
void dfs(int sum,int x){
	if(x==0)return;
	dfs(sum-a[x],chose[sum-a[x]]);
	ans[++ans[0]]=a[x];
}
signed main(){
	freopen("157.in","r",stdin);freopen("157.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]),sum+=a[i];
	sort(a+1,a+1+n);
	memset(f,0,sizeof(f));f[0]=1;
	for(i=1;i<=n;i++){
		for(j=m;j>=a[i];j--){
			if(f[j]==0&&f[j-a[i]]==1){
				f[j]=1;num[j]=num[j-a[i]]+1;
				chose[j]=i;
			}
			else if(f[j]==1&&f[j-a[i]]==1){
				if(num[j-a[i]]+1>=num[j]){
					chose[j]=i;
					num[j]=num[j-a[i]]+1;
				}
			}
		}
		if(a[i]>m)break;
	}
	if(f[m]==1){
		dfs(m,chose[m]);
		for(i=1;i<=ans[0];i++){
			if(i==ans[0])printf("%lld",ans[i]);
			else printf("%lld ",ans[i]);
		}
	}
	else printf("No Solution\n");
	fclose(stdin);fclose(stdout);
	return 0;
}
