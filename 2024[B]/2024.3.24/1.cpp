#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	int ans=n%10;
	if(ans==0){
		cout<<0<<endl;
	}
	else{
		cout<<10-ans<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
