#include<bits/stdc++.h>
using namespace std;
int i,n,T;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		cin>>n;
		for(i=1;i<=n;i++){
			if(i==n)printf("%d\n",i);
			else printf("%d ",i);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
