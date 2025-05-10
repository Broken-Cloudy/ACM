#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,j,SG[10000009],ans,x,NUM;
int prime[10000009],cnt;//cnt是素数的个数，prime里面全部都是素数 
int flag[10000009];//0是质数，>0不是质数 
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	flag[1]=1;
	for(i=2;i<=10000000;i++){
		if(flag[i]==0){
			prime[++cnt]=i;//记录下来 
		}
		for(j=1;j<=cnt&&i*prime[j]<=10000000;j++){
			flag[prime[j]*i]=prime[j];//一下子筛到底(最小因数) 
			//当然，i肯定比prime[j]大，因为prime[j]是在i之前得出的
			if(i%prime[j]==0)break;
		}
	}
	SG[0]=0;SG[1]=1;NUM=1;
	for(i=2;i<=10000000;i++){
		if(i%2==0)SG[i]=0;
		else{
			if(flag[i]==0){//是质数 
				SG[i]=++NUM;
			}
			else{//不是质数 
				SG[i]=SG[flag[i]];
			}
		}
	}
	cin>>T;
	while(T--){
		scanf("%lld",&n);ans=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&x);
			ans^=SG[x];
		}
		if(ans==0)printf("Bob\n");
		else printf("Alice\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
