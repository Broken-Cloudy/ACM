#include<bits/stdc++.h>
#define int long long
using namespace std;
int x,y,z,k[100009],i,a,b,c,A,B,C,ans[100009];
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>x>>y>>z;
	if(z>=y&&z>=x&&y>=x){
		a=1;b=2;c=3;
		C=z;B=y;A=x;
	}
	else if(z>=y&&z>=x&&x>=y){
		a=2;b=1;c=3;
		C=z;B=x;A=y;
	}
	else if(x>=y&&x>=z&&z>=y){
		a=2;b=3;c=1;
		A=y;B=z;C=x;
	}
	else if(x>=y&&x>=z&&y>=z){
		a=3;b=2;c=1;
		A=z;B=y;C=x;
	}
	else if(y>=z&&y>=x&&x>=z){
		a=3;b=1;c=2;
		A=z;B=x;C=y;
	}
	else{
		a=1;b=3;c=2;
		A=x;B=z;C=y;
	}
	for(i=1;i<=x+y+z;i++){
		scanf("%lld",&k[i]);
	}
	for(i=1;i<=x+y+z;i++){
		if(k[i]==c&&A>0){
			A--;
			ans[i]=a;
		}
	}
	for(i=1;i<=x+y+z;i++){
		if(k[i]==c&&ans[i]==0&&B>0){
			B--;
			ans[i]=b;
		}
	}
	for(i=1;i<=x+y+z;i++){
		if(k[i]==b&&C>0){
			C--;
			ans[i]=c;
		}
	}
	for(i=1;i<=x+y+z;i++){
		if(k[i]==a&&C>0){
			C--;
			ans[i]=c;
		}
	}
	for(i=1;i<=x+y+z;i++){
		if(ans[i]==0){
			if(k[i]==c){
				ans[i]=c;
				C--;
			}
		}
	}
	for(i=1;i<=x+y+z;i++){
		if(ans[i]==0){
			if(k[i]==a){
				if(C>0){
					ans[i]=c;
					C--;
				}
				else if(B>0){
					ans[i]=b;
					B--;
				}
			}
		}
	}
	for(i=1;i<=x+y+z;i++)printf("%lld ",ans[i]);
	fclose(stdin);fclose(stdout);
	return 0;
}
