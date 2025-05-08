#include<iostream>
#include<cstdio>
using namespace std;
int T,n,k,j,i;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		cin>>n>>k;
		for(i=1;i<=n;i++){
			char c='a';
			for(j=1;j<=k;j++){
				putchar(c);
				c++;
			}
		}
		cout<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
