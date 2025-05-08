#include<bits/stdc++.h>
using namespace std;
int a,vis[12],num[12],x,n;
void dfs(int x){
	int i;
	if(x==n+1){
		for(i=1;i<=n;i++){
			if(i==n)printf("%d\n",num[i]);
			else printf("%d ",num[i]);
		}
	}
	else{
		for(i=1;i<=n;i++){
			num[x]=i;
			dfs(x+1);
		}
	}
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	dfs(1);
	fclose(stdin);fclose(stdout);
	return 0;
} 
