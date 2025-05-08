#include<bits/stdc++.h>
using namespace std;
int T,n,i,a[10009],ans;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d",&n);ans=0;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		for(i=1;i<=n;i++)ans^=a[i];
		if(ans>0){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
