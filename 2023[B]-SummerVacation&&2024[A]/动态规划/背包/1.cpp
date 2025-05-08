#include<bits/stdc++.h>
using namespace std;
int hh1,mm1,hh2,mm2,i,n,j,k;
int w[10090],c[10090],P[10090],f[10090];
char cc;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	scanf("%d%c%d%d%c%d",&hh1,&cc,&mm1,&hh2,&cc,&mm2);
	int t=(hh2-hh1)*60+(mm2-mm1);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&w[i],&c[i],&P[i]);
	}
	for(i=1;i<=n;i++){
		if(P[i]==0){//无限背包 
			for(j=w[i];j<=t;j++){
				f[j]=max(f[j],f[j-w[i]]+c[i]);
			}
		}
		else{
			for(k=1;k<=P[i];k++){//取几次 
				for(j=t;j>=w[i];j--){
					f[j]=max(f[j],f[j-w[i]]+c[i]);
				}
			}
		}
	}
	cout<<f[t]<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
