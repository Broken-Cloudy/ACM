#include<bits/stdc++.h>
using namespace std;
int a,k;
int main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	while(true){
		scanf("%d",&a);
		if(a==1){
			k++;
		}
		else if(a==0){
			printf("%d\n",k);
		}
		else{
			break;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
