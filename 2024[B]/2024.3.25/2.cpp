#include<iostream>
#include<cstring>
using namespace std;
void upper_to_lower(string &);
int main(){
	//freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	string str;
	getline(cin,str);
	upper_to_lower(str);
	cout<<str;
	fclose(stdin);fclose(stdout);
	return 0;
}
void upper_to_lower(string &str1){
	int i=0;
	while(str1[i]!='\0'){
		if(str1[i]>='A'&&str1[i]<='Z'){
			str1[i]+=32;
		}
		i++;
	}
}
