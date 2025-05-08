#include<bits/stdc++.h>
using namespace std;
string k;
map<string,int>a;
int n,i,m;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>k;
		a[k]=1;
	}
	cin>>m;
	for(i=1;i<=m;i++){
		cin>>k;
		if(a[k]==1){
			puts("OK");
			a[k]=2;
		}
		else if(a[k]==2){
			puts("REPEAT");
		}
		else{
			puts("WRONG");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
