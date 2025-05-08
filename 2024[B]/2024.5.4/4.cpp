#include<bits/stdc++.h>
using namespace std;
string s;
bool f=0;
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	while(cin>>s){
		if(f==1)cout<<' ';
		else f=1;
		if(s=="henan")cout<<"Henan";
		else cout<<s;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
