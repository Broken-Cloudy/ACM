#include<bits/stdc++.h>
using namespace std;
char c[19];
int T,i,n,k1,k2,ans;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d",&n);getchar();
		for(i=1;i<=n;i++){
			c[i]=getchar();
		}
		for(i=1;i<=n;i++){
			if(c[i]=='B'){
				k1=i;
				break;
			}
		}
		for(i=n;i>=1;i--){
			if(c[i]=='B'){
				k2=i;
				break;
			}
		}
		ans=k2-k1+1;
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
