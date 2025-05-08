#include<bits/stdc++.h>
using namespace std;
int a,b,k;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>a>>b>>k;
	if(a>=k*b){
		cout<<"good"<<endl;
	}
	else{
		cout<<"bad"<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
