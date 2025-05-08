#include<bits/stdc++.h>
using namespace std;
int i,n,j,T,ji,ou,a[30],x,y,z,xx,yy,zz;
bool f=0;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){  
		scanf("%d",&n);
		if(n==1){
			scanf("%d%d%d",&x,&y,&z);
			if(x==y&&z==1){
				printf("No\n");
			}
			else printf("Yes\n");
		}
		else{
			scanf("%d%d%d",&x,&y,&z);
			scanf("%d%d%d",&xx,&yy,&zz);
			if(x==yy&&y==xx&&z==zz){
				printf("No\n");
			}
			else if(x==xx&&y==yy&&z!=zz)printf("No\n");
			else printf("Yes\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
