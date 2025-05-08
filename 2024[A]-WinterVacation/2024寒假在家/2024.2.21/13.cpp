#include<bits/stdc++.h>
using namespace std;
int n,T,i,a[100009][3],ans,kuai;
int main(){
	freopen("13.in","r",stdin);freopen("13.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d",&n);ans=1e9+7;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i][1]);
		}
		for(i=1;i<=n;i++){
			scanf("%d",&a[i][2]);
			if(a[i-1][1]==a[i][2]||a[i+1][1]==a[i][2])ans=1;
			else if(a[i][1]==a[i][2]&&i!=1&&i!=n){
				ans=1;
			}
		}
		if(n==1){
			printf("-1\n");
		}
		else if(n==2){
			if(a[1][1]!=a[1][2])printf("1\n");
			else printf("-1\n");
		}
		else{
			ans=max(ans,1);
			ans=min(ans,2);
			printf("%d\n",ans);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
