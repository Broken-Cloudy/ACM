#include<bits/stdc++.h>
using namespace std;
int n,c,i,d,ans;
int main(){
	freopen("10.in","r",stdin);freopen("10.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d",&c);
		if(c<=0){
			printf("0\n");
		}
		else{
			scanf("%d",&d);
			ans=c+d*20;
			printf("%d\n",ans);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
