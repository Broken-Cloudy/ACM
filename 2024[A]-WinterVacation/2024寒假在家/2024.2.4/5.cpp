#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[409],i,d,h=1,sum,anss=99999999;
int vis[409],ans[400009],cc[400009];
bool f=0;
void dfs(int num,int ci){
	int i;
	if(ans[num+200000]==1&&ci>=cc[num+200000])return;
	ans[num+200000]=1;cc[num+200000]=ci;
	if(num==0){
		anss=min(ci,anss);
		f=1;
	}
	for(i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(num+a[i],ci+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
	for(i=1;i<=n;i++)a[i]=a[i]*(-2);
	dfs(sum,0);
	if(f==0)printf("-1\n");
	else printf("%d\n",anss);
	fclose(stdin);fclose(stdout);
	return 0;
}
