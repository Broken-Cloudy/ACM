#include<bits/stdc++.h>
using namespace std;
int T,n,ans[200009],i,k;
int main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	for(i=1;i<=200005;i++){
		int t=i;k=0;
		while(t>0){
			k+=t%10;
			t/=10;
		}
		ans[i]=ans[i-1]+k;
	}
	for(int o=1;o<=T;o++){
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
