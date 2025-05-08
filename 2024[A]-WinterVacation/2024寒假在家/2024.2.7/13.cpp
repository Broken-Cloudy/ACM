#include<bits/stdc++.h>
using namespace std;
long long i,n,f[309][3],k,wei,ans,j,rmb[12];//f[][0]能被4整除 f[][1]不能被4整除
bool ff=0,fff=0;
int main(){
	freopen("13.in","r",stdin);freopen("13.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		ff=0;wei=0;fff=0;
		scanf("%lld",&k);
		if(k<10)rmb[k]++;
		if(k%4!=0)ff=1;
		if(k%2!=0)fff=1;//ji
		while(k>0){
			wei+=k%10;
			k/=10;
		}
		if(ff==1)f[wei][1]++;
		else f[wei][0]++;
		if(fff==1)f[wei][2]++;//ji
	}
	for(k=1;k<=18;k++){//9的倍数 
		for(i=1;i<=4;i++){
			for(j=1;j<=18;j++){
				ans+=f[(k-1)*9+i][0]*f[j*9-i][1];
				ans+=f[(k-1)*9+i][1]*f[j*9-i][0];
				ans+=f[(k-1)*9+i][0]*f[j*9-i][0]*2;
			}
		}
	}
	for(k=1;k<=18;k++){//9的倍数 
		for(j=k;j<=18;j++){
			if(j==k){
				ans+=f[k*9][0]*f[j*9][1];
				ans+=f[k*9][0]*(f[j*9][0]-1);
			}
			else{
				ans+=f[k*9][0]*f[j*9][1];
				ans+=f[k*9][1]*f[j*9][0];
				ans+=f[k*9][0]*f[j*9][0]*2;
			}
			
		}
	}
	for(j=1;j<=18;j++){
		ans+=rmb[2]*f[j*9-2][2];
		ans+=rmb[6]*f[j*9-6][2];
	}
	ans-=rmb[5]*rmb[4];
	ans-=rmb[1]*rmb[8];
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
