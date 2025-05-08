#include<bits/stdc++.h>
using namespace std;
int T,n,k;
int main(){
	freopen("1.in","r",stdin);freopen("1.in","r",stdin);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d%d",&n,&k);
		printf("%d\n",(n-1)*k+1);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
