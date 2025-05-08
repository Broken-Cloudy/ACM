#include<bits/stdc++.h>
using namespace std;
int q,i,ans[100000008],anss,j,t; 
bool flag[100000008];
int main(){
	freopen("prg04.in","r",stdin);freopen("prg04.out","w",stdout);
	flag[1]=1; 
	for(i=2;i<=100000000;i++){
		if(flag[i]==0){
			ans[++anss]=i;
		}
		for(j=1;j<=anss&&i*ans[j]<=100000000;j++){
			flag[ans[j]*i]=1;
			if(i%ans[j]==0)break;
		}
	}
	for(i=1;i<=1000000;i++){
		scanf("%d",&t);
		if(flag[t]==1)puts("NO");
		else puts("YES");
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
