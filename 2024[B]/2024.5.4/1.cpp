#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,k;
int a[309][309],f[309],ans;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){//ÐÐ 
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++)f[i]=1;
	for(k=2;k<=n;k++){
		for(i=1;i<k;i++){
			bool flag=0;
			for(j=1;j<=m;j++){//ÐÐÍÆ 
				if(a[k][j]>=a[i][j]){
					flag=1;break;
				}
			}
			if(flag==0)f[k]=max(f[k],f[i]+1);
			else continue;
		}
	}
	for(i=1;i<=n;i++)ans=max(ans,f[i]);
	cout<<n-ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
