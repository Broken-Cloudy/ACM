#include<iostream>
#include<cstdio>
using namespace std;
int n,q,i,ans[2300008],anss,j,t,k;//标记质数 
bool flag[2300008];//0是质数，1不是质数 
int gz[2300008];
int main(){
	freopen("8.in","r",stdin);freopen("8.out","w",stdout);
	cin>>n;t=n;
	flag[1]=1; 
	for(i=2;i<=2000009;i++){
		if(flag[i]==0){
			ans[++anss]=i;//记录下来 
		}
		for(j=1;j<=anss&&i*ans[j]<=2000009;j++){
			flag[ans[j]*i]=1;//一下子筛到底 
			//当然，i肯定比ans[j]大，因为ans[j]是在i之前得出的
			if(i%ans[j]==0)break;
		}
	}
	while(n>0){
		for(i=1;i<=n;i++){
			if(flag[i+n]==0){
				int r=(i+n)/2;
				for(j=i,k=n;j<=r;j++,k--){
					gz[j]=k;
					gz[k]=j;
				}
				n=i-1;
			}
		}
	}
	n=t;
	for(i=1;i<=n;i++){
		if(i!=n)printf("%d ",gz[i]);
		else{
			printf("%d\n",gz[i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
