#include<bits/stdc++.h>
using namespace std;
char s[109];
int a,b,T,i,n;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%s",s+1);
		a=0;b=0;
		for(i=1;i<=5;i++){
			if(s[i]=='A')a++;
			else b++;
		}
		if(a>=b)printf("A\n");
		else{
			printf("B\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
