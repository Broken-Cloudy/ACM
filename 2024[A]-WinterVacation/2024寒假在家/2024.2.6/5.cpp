#include<bits/stdc++.h>
using namespace std;
int a[200009];
int T,i,n,k,ans,small,big,j;
int main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d%d",&n,&k);
		small=1;big=n;
		for(j=0;j<=k/2-1;j++){//ÏîÄÚ 
			for(i=0;i<=(n+k-1)/k-1;i++){//
				if(i*k+(j*2+1)<=n){
					a[i*k+(j*2+1)]=big;
					big--;	
				}
				if(i*k+(j*2+2)<=n){
					a[i*k+(j*2+2)]=small;
					small++;
				}
			}
		}
		for(i=1;i<=n;i++){
			if(i!=n)printf("%d ",a[i]);
			else printf("%d\n",a[i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
