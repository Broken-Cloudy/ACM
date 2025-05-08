#include<bits/stdc++.h>
using namespace std;
int a=5;
void fun(int b){
	int a=10;
	a+=b;
	cout<<a<<endl;
}
int main(){
	//freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	int c=20;
	fun(c);
	a+=c;
	cout<<a<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
} 
