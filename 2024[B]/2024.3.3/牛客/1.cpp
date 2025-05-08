#include<bits/stdc++.h>
using namespace std;
char s[100009];
int len,i;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	scanf("%s",s+1);
	len=strlen(s+1);
	for(i=1;i<=len/2;i++)putchar(s[i]);
	putchar('\n');
	for(i=len/2+1;i<=len;i++)putchar(s[i]);
	putchar('\n');
	fclose(stdin);fclose(stdout);
	return 0;
}
