#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	string str="The apple thinks apple is delicious.";
	string key="apple";
	int pos1=str.find(key);
	int pos2=str.find(key,10);
	cout<<pos1<<endl;
	cout<<pos2<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
