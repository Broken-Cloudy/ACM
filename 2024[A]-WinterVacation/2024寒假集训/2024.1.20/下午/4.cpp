#include<iostream>
#include<cstdio>
#pragma GCC optimize(2)
using namespace std;
int n,a[19][19],i,j;
int vis[109];
int maxsum=0;
long long K;
void dfs(int deep, int currentSum) {
    if (deep == n+1) {
        // 已经处理完所有行
        maxsum = max(maxsum, currentSum);
        return;
    }
    for (int col = 1; col <=13; ++col) {
        if (!vis[col]) {
            vis[col] = 1;
            dfs(deep + 1, currentSum +a[deep][col]);
            vis[col] = 0;
        }
    }
}
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)scanf("%d",&a[i][j]);
	dfs(1,0);
	cout<<maxsum<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
