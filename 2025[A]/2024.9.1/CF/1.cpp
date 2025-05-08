#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,a,b,ans;
bool f=0;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>a>>b;f=0;
		for(i=0;i<=a;i++){
			for(j=0;j<=b;j++){
				if(i*1+(a-i)*(-1)+j*2+(b-j)*(-2)==0)f=1;
			}
		}
		if(f==1)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
