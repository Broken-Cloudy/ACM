#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,j,SG[10000009],ans,x,GCD,sg[3009];
int prime[10000009],cnt;//cnt是素数的个数，prime里面全部都是素数 
bool flag[10000009];//0是质数，1不是质数 
void gcd(int a,int b){
	if(b==0){
		GCD=a;
		return;
	}
	else gcd(b,a%b);
}
signed main(){
	freopen("3pro.in","r",stdin);freopen("3pro.out","w",stdout);
	flag[1]=1;
	for(i=2;i<=10000000;i++){
		if(flag[i]==0){
			prime[++cnt]=i;//记录下来 
		}
		for(j=1;j<=cnt&&i*prime[j]<=n;j++){
			flag[prime[j]*i]=1;//一下子筛到底 
			//当然，i肯定比ans[j]大，因为ans[j]是在i之前得出的
			if(i%prime[j]==0)break;
		}
	}
	SG[0]=0;SG[1]=1;
	for(i=2;i<=1000;i++){
		memset(sg,0,sizeof(sg));
		for(j=0;j<i;j++){
			gcd(i,j);
			if(GCD==1){
				sg[SG[j]]=1;
			}
		}
		for(j=0;j<=i;j++){
			if(sg[j]==0){
				SG[i]=j;
				break;
			}
		}
	}
	for(i=1;i<=1000;i++)cout<<SG[i]<<' ';
	fclose(stdin);fclose(stdout);
	return 0;
}
