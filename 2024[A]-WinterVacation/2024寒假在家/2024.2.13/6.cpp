#include<bits/stdc++.h>
using namespace std;
int T,n,k,i,j,a[200009],b[200009],r,qian,hou,c[200009],d;
bool f;
int main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d%d",&n,&k);f=0;
		if(k==1)f=1;
		for(i=1;i<=k;i++){
			if(i==1){
				for(j=1;j<=n;j++){
					scanf("%d",&a[i]);
				}
			}
			else if(i==2){
				for(j=1;j<=n;j++){
					scanf("%d",&b[i]);
				}
			}
			else{
				if(k==3){
					r=a[1];
					for(d=1,j=2;j<=n;d++,j++){
						c[d]=a[j];
					}
					for(j=2;j<=n;j++){
						if(b[j]==r){
							for(i=1;i<=n;i++){
								
							}
						}
					}
				}
			}
		}
		if(f==1){
			printf("YES\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
