#include<bits/stdc++.h>
using namespace std;
int T,i,n,m;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d%d",&n,&m);
		printf("%d\n",n*(m/2));
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
