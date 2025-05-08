#include<bits/stdc++.h>
using namespace std;
int a,b;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>a>>b;
	if(a>b)cout<<"kou"<<endl;
	if(a==b)cout<<"draw"<<endl;
	if(a<b)cout<<"yukari"<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
