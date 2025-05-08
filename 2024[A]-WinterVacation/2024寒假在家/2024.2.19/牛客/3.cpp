#include<bits/stdc++.h>
using namespace std;
char a[109][109],b[109];
int n,m,x,y,zz[109],i,j,opop[109],p,q;
int main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n>>m>>x>>y;
	for(i=1;i<=n;i++){
		getchar();
		for(j=1;j<=m;j++){
			a[i][j]=getchar();
		}
	}
	cin>>p>>q;
	for(int o=1;o<=q;o++){
		scanf("%d%d",&opop[o],&zz[o]);
	}
	for(int o=1;o<=p;o++){
		for(int k=1;k<=q;k++){
			int op=opop[k];
			int z=zz[k];
			if(op==1){//ÐÐ 
				for(i=1;i<m;i++){
					b[i+1]=a[z][i];
				}
				b[1]=a[z][m];
				for(i=1;i<=m;i++){
					a[z][i]=b[i];
				}
			}
			else{
				for(i=1;i<n;i++){
					b[i+1]=a[i][z];
				}
				b[1]=a[n][z];
				for(i=1;i<=n;i++){
					a[i][z]=b[i];
				}
			}
		}
	}
	cout<<a[x][y]<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
