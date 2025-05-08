#include<bits/stdc++.h>
using namespace std;
int T,A,B,C,ans;
int main(){
	freopen("10.in","r",stdin);freopen("10.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d",&A);
		if(A<=0)ans=0;
		else{
			scanf("%d",&B);
			ans=A+B*20;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
