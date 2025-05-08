#include<bits/stdc++.h>
using namespace std;
int i,cnt1,cnt2,cnt3,j;
char s[100010],a[100010],b[100010],c[100010];
int main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(i=1;i<=len;i++){
		if(s[i]=='x'&&s[i+1]=='i'&&s[i+2]=='a'&&s[i+3]=='o'){
			a[++cnt1]='x';a[++cnt1]='i';a[++cnt1]='a';a[++cnt1]='o';
			i+=3;
		}
		else if(s[i]=='h'&&s[i+1]=='o'&&s[i+2]=='n'&&s[i+3]=='g'){
			b[++cnt2]='h';b[++cnt2]='o';b[++cnt2]='n';b[++cnt2]='g';
			i+=3;
		}
		else{
			c[++cnt3]=s[i];
		}
	}
	for(i=1;i<=cnt1;i++){
		putchar(a[i]);
		if(i%4==0&&j<cnt2){
			for(int k=1;k<=4;k++)putchar(b[++j]);
		}
	}
	while(j<cnt2){
		putchar(b[++j]);
	}
	for(i=1;i<=cnt3;i++){
		putchar(c[i]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
