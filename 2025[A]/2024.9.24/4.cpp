#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n;
deque<char>q;
string s;
bool ff;
bool ask(string ss){
	bool f;
	cout<<'?'<<' '<<ss<<endl;fflush(stdout);
	cin>>f;
	return f;
}
void solve(int x){
	ff=0;
	while(x){
		if(ff==0){
			s+='0';
			if(ask(s)){x--;}
			else{
				s.erase(s.length()-1);s+='1';
				if(ask(s)){x--;}
				else{ff=1;s.erase(s.length()-1);}
			}
		}
		else{
			s.insert(0,"0");
			if(ask(s)){x--;}
			else{
				s.erase(0,1);s.insert(0,"1");
				x--;
			}
		}
	}
}
signed main(){
	//freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;s.clear();
		solve(n);
		cout<<'!'<<' '<<s<<endl;fflush(stdout);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
