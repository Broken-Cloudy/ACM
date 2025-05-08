#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,b,i,len,k,ans;
char a[1000009],c;
void gcd(int x,int y){
	if(y==0)ans=x;
	else gcd(y,x%y);
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	while(c!='\n'){
		c=getchar();
		a[++len]=c;
	}
	cin>>b;
	for(i=1;i<len;i++){
		if(k>=b){
			k%=b;
		}
		k=k*10+(a[i]-48);
	}
	gcd(b,k);
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
