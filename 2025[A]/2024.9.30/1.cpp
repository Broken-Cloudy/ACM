#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,t,j,r;
char c[9];
void putout(int x){
	if(x==1)putchar('a');
	if(x==2)putchar('e');
	if(x==3)putchar('i');
	if(x==4)putchar('o');
	if(x==5)putchar('u');
	return;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		t=n/5;r=n-5*t;
		for(j=1;j<=5;j++){
			for(i=1;i<=t;i++){
				putout(j);
			}
			if(r>0){
				putout(j);r--;
			}
		}
		putchar('\n');
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
