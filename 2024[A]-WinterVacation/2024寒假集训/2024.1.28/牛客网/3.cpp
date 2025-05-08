#include<bits/stdc++.h>
using namespace std;
int i,ans;
char a[100010],k;
int main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	scanf("%s",a+1);
	int len=strlen(a+1);
	if(len<=3){
		printf("-1\n");
		return 0;
	}
	k=a[1];
	for(i=2;i<=len/2;i++){
		if(len%2==1&&i==len){
			printf("-1\n");
			return 0;
		}
		if(a[i]!=k){
			ans=i;
			break;
		}
	}
	if(i==len/2+1){
		printf("-1\n");
		return 0;
	}
	swap(a[1],a[i]);swap(a[len],a[len-i+1]);
	for(i=1;i<=len;i++){
		putchar(a[i]);
	}
	printf("\n");
	fclose(stdin);fclose(stdout);
	return 0;
}
