#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
signed main(){
	//freopen("4.in","r",stdin);fclose("4.out","w",stdout);
	cin>>n;
	if(n==0){
		cout<<"1 1 1"<<endl;
		cout<<"1 1 1"<<endl;
		cout<<"1 1 1"<<endl;
	}
	else if(n>0){
		cout<<"2 1 1"<<endl;
		cout<<"1 ";cout<<n+1;cout<<" 1"<<endl;
		cout<<"1 1 1"<<endl;
	}
	else{
		cout<<"2 1 1"<<endl;
		cout<<"1 1 ";cout<<(-n)+1<<endl;
		cout<<"1 1 1"<<endl;
	}
	//fclose(stdin);fclose(stdout);
	return 0;
}
