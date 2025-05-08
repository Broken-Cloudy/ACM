#include<bits/stdc++.h>
using namespace std;
char c;
int a[12][12],b,T,i,n,j;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++){
			getchar();
			for(j=1;j<=n;j++){
				c=getchar();
				a[i][j]=c-'0';
			}
		}
		bool f=0;
		for(i=1;i<=n;i++){
			if(f==1)break;
			for(j=1;j<=n;j++){
				if(a[j][i]==1){
					if(a[j-1][i]==1||a[j+1][i]==1){
						f=1;
						printf("SQUARE\n");
						break;
					}
					else{
						f=1;
						printf("TRIANGLE\n");
						break;
					}
				}
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
