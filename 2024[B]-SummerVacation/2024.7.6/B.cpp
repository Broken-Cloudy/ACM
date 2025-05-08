#include<bits/stdc++.h>
using namespace std;
char c[1209];
int a,k=1,i;
int main(){
	freopen("B.in","r",stdin);freopen("B.out","w",stdout);
	for(i=1;i<=32;i++)c[i]=getchar();
	for(i=32;i>=2;i--){
		a+=(c[i]-48)*k;
		k*=2;
	}
	if(c[1]==49)a=-a;
	if(a==0){
		for(i=32;i>=1;i--){
			cout<<0;
		}
	}
	else{
		cout<<c[1];
		a=~a;
		for(i=1;i<=31;i++){
			if((a&(1<<(i-1)))==0)a+=(1<<(i-1));
			else a-=(1<<(i-1));
		}
		for(i=31;i>=1;i--){
			if((a&(1<<(i-1)))==0)cout<<0;
			else cout<<1;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
