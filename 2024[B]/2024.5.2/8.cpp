#include<bits/stdc++.h>
using namespace std;
int T,n,i;
double ans,num=sqrt(2);
int main(){
	freopen("8.in","r",stdin);freopen("8.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		cin>>n;ans=1;
		for(i=1;i<n;i++){
			ans*=num;
		}
		printf("%.2lf\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
