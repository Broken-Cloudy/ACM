#include<bits/stdc++.h>
using namespace std;
int x,y;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>x>>y;
	if(x%2==0&&y%2==0){
		cout<<x<<' '<<y<<" ^_^!"<<endl;
	}
	else{
		cout<<x<<' '<<y<<" -_-"<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
