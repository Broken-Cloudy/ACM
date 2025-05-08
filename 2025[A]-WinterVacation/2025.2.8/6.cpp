#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,kk,cnt,x,o;
char c[6][6];
int FF;
struct nod{
	int i,j;
}a[7];
int check(){
	int i,j;
	int ans=0;
	for(i=1;i<=3;i++)if(c[i][1]=='X'&&c[i][2]=='X'&&c[i][3]=='X')ans=1;
	for(j=1;j<=3;j++)if(c[1][j]=='X'&&c[2][j]=='X'&&c[3][j]=='X')ans=1;
	if(c[1][1]=='X'&&c[2][2]=='X'&&c[3][3]=='X')ans=1;
	if(c[1][3]=='X'&&c[2][2]=='X'&&c[3][1]=='X')ans=1;
	return ans;
}
void dfs(int x,int X,int O){
	if(FF>0)return;
	if(x==cnt+1){
		if(X==O+1){
			FF=max(FF,check());
		}
		return;
	}
	else{
		c[a[x].i][a[x].j]='X';
		dfs(x+1,X+1,O);
		c[a[x].i][a[x].j]='O';
		dfs(x+1,X,O+1);
	}
}
signed main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>T;
	while(T--){
		kk=0;cnt=0;FF=0;x=0;o=0;
		memset(a,0,sizeof(a));
		for(i=1;i<=3;i++){
			getchar();
			for(j=1;j<=3;j++){
				c[i][j]=getchar();
			}
		}
		for(i=1;i<=3;i++){
			for(j=1;j<=3;j++){
				if(c[i][j]!='G'){
					kk++;
				}
			}
		}
		if(kk<=2){
			printf("Yes\n");
			continue;
		}
		else{
			for(i=1;i<=3;i++){
				for(j=1;j<=3;j++){
					if(c[i][j]=='G'){
						cnt++;
						a[cnt].i=i;
						a[cnt].j=j;
					}
					else if(c[i][j]=='X'){
						x++;
					}
					else o++;
				}
			}
			dfs(1,x,o);
			if(FF==0)printf("No\n");
			else printf("Yes\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
