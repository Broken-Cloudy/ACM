#include<bits/stdc++.h>
using namespace std;
map<string,string>m;
string s1,s2;
int N,M,i;
int main(){
	freopen("E.in","r",stdin);freopen("E.out","w",stdout);
	cin>>N>>M;
	for(i=1;i<=N;i++){
		cin>>s1>>s2;
		m[s1]=s2;
	}
	for(i=1;i<=M;i++){
		cin>>s1;
		if(!m[s1].empty()){
			cout<<m[s1]<<endl;
		}
		else cout<<"NULL"<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
