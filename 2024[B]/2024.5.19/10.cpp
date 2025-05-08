#include<bits/stdc++.h>
using namespace std;
int n,j,i,pow2[35],N;
char c[1036][1036];
void dfs(int x,int y,int deep){
	int i,j;
	if(deep==1){
		for(i=x;i<=x+1;i++){
			for(j=y;j<=y+1;j++){
				putchar(c[i][j]);
			}
		}
	}
	else{
		dfs(x,y,deep-1);
		dfs(x,y+pow2[deep-1],deep-1);
		dfs(x+pow2[deep-1],y,deep-1);
		dfs(x+pow2[deep-1],y+pow2[deep-1],deep-1);
	}
}
int main(){
	freopen("10.in","r",stdin);freopen("10.out","w",stdout);
	cin>>n;getchar();pow2[0]=1;
	for(i=1;i<=30;i++){
		pow2[i]=pow2[i-1]*2;
		if(n==pow2[i])N=i;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			c[i][j]=getchar();
		}
		getchar();
	}
	dfs(1,1,N);
	fclose(stdin);fclose(stdout);
	return 0;
}
