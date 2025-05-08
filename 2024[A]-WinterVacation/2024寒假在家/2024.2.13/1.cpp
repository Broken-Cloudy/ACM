#include<bits/stdc++.h>
using namespace std;
int T,k;
char a,b,c;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d",&k);
		if(k<=28){
			putchar('a');putchar('a');putchar(k-3+'a');
		}
		else if(k>28&&k<=53){
			putchar('a');putchar(k-28+'a');putchar('z');
		}
		else{
			putchar(k-53+'a');putchar('z');putchar('z');
		}
		putchar('\n');
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
