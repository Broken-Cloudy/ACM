#include<bits/stdc++.h>
using namespace std;
int T,a,n,a1[100009],a2[100009],i,ans1,ans2,num1,num0,n1,n0;
char c;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		ans1=0;ans2=0;
		scanf("%d",&n);
		getchar();
		for(i=1;i<=n;i++){
			c=getchar();
			a1[i]=c-48;
		}
		getchar();
		for(i=1;i<=n;i++){
			c=getchar();
			a2[i]=c-48;
		}
		for(i=1;i<=n;i++){
			if(a1[i]==1&&a2[i]==0)ans1++;
			if(a2[i]==1&&a1[i]==0)ans2++;
		}
		printf("%d\n",max(ans1-ans2,ans2-ans1)+min(ans1,ans2));
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
