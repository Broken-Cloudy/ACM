#include<bits/stdc++.h>
using namespace std;
int n,x,i,sl,shib;
bool f=0;
int main(){
	freopen("12.in","r",stdin);freopen("12.out","w",stdout);
	cin>>n>>x;sl=n;shib=0;
	for(i=n;i>=-n;i-=2){
		if(i==x){
			f=1;
			break;
		}
		else{
			sl--;shib++;
		}
	}
	if(f==1){
		cout<<sl<<' ';
		cout<<shib<<endl;
	}
	else{
		cout<<-1<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
