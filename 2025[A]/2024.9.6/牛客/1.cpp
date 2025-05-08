#include<bits/stdc++.h>
#define int long long 
using namespace std;
bool f;
int a,b,c;
bool jud(int x,int y,int z){
	if(x>=y&&x>=z){
		if(y+z>x)return 1;
		else return 0;
	}
	else if(y>=x&&y>=z){
		if(x+z>y)return 1;
		else return 0;
	}
	else{
		if(x+y>z)return 1;
		else return 0;
	}
}
signed main(){
	//freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>a>>b>>c;
	if(jud(a*2,b,c)==1)f=1;
	if(jud(a,b*2,c)==1)f=1;
	if(jud(a,b,c*2)==1)f=1;
	if(f==1){
		cout<<"Yes"<<endl;
	}
	else cout<<"No"<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
