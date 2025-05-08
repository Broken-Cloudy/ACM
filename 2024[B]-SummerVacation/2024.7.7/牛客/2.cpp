#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c,ans;
signed main(){
    cin>>a>>b>>c;
    if(a==1&&b==1&&c==1){
    	cout<<3<<endl;
	}
	else if((a==1&&c==1)||(a==1&&b==1)||(b==1&&c==1)){
    	cout<<2*max(max(a,b),max(b,c))<<endl;
	}
	else if(a==1||b==1||c==1){
		if(a==1){
			if(b>=c){
				cout<<(c+1)*b<<endl;
			}
			else{
				cout<<(b+1)*c<<endl;
			}
		}
		else if(b==1){
			if(a>=c){
				cout<<(c+1)*a<<endl;
			}
			else{
				cout<<(a+1)*c<<endl;
			}
		}
		else if(c==1){
			if(b>=a){
				cout<<(a+1)*b<<endl;
			}
			else{
				cout<<(b+1)*a<<endl;
			}
		}
	}
	else{
		cout<<(a*b*c)<<endl;
	}
    return 0;
}
