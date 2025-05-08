#include<iostream>
#include<cstdio>
using namespace std;
int i,j,m,n,f[100100][54],log2[100100],po=1,x,y,s;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)scanf("%d",&f[i][0]);
	log2[0]=-1;
	for(i=1;i<=100000;i++){
		if(i>=po){
			po*=2;
			log2[i]=log2[i-1]+1;
		}
		else log2[i]=log2[i-1];
	}
	for(j=1;j<=log2[n];j++){
		for(i=1;i<=n-(1<<j)+1;i++){
			f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
		}
	}
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		s=log2[y-x+1];//×¢Òâ¼Ó1 
		printf("%d ",min(f[x][s],f[y-(1<<s)+1][s]));
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
