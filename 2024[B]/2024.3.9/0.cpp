#include<bits/stdc++.h>
using namespace std;
const int N=2200009,M=29;
int vis[N],f[N],n,K,i,j,visnow[M],now[M],k,zhan[N],h,d;
void dfs(int deep){
	int i;
	if(deep==k+1){
		for(i=1;i<=k;i++){
			if(i==k)printf("%d\n",now[i]);
			else printf("%d ",now[i]);
		}
		return;
	}
	else{
		for(i=1;i<=k;i++){
			if(visnow[i]==0){
				visnow[i]=1;
				now[i]=0;
				dfs(deep+1);
				now[i]=1;
				dfs(deep+1);
				visnow[i]=0;
				break;
			}
		}
	}
}
int main(){
	freopen("0.in","r",stdin);freopen("0.out","w",stdout);
	k=6;dfs(1);
	fclose(stdin);fclose(stdout);
	return 0;
}
