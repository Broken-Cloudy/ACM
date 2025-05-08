#include<bits/stdc++.h>
using namespace std;
int a[109][109],f[109][109],pre[109][109],ans,kk;
int F,V,i,j,k;
void dfs(int x,int y){
	if(y>1){
		dfs(pre[y][x],y-1);
	}
	cout<<x<<' ';
}
int main(){
	freopen("11.in","r",stdin);freopen("11.out","w",stdout);
	cin>>F>>V;
	memset(f,0x8f,sizeof(f));
	for(i=1;i<=F;i++){
		for(j=1;j<=V;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1;i<=V;i++){
		f[1][i]=a[1][i];
	}
	for(i=2;i<=F;i++){
		for(j=i;j<=V;j++){
			for(k=i-1;k<j;k++){
				if(f[i-1][k]+a[i][j]>f[i][j]){
					f[i][j]=f[i-1][k]+a[i][j];
					pre[i][j]=k;
				}
			}
		}
	}
	for(i=1;i<=V;i++){
		if(f[F][i]>=ans){
			kk=i;
			ans=f[F][i];
		}
	}
	cout<<ans<<endl;
	dfs(kk,F);
	fclose(stdin);fclose(stdout);
	return 0;
} 
