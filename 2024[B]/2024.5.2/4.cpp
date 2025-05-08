#include<bits/stdc++.h>
using namespace std;
char a[1200],c,b[1200],d;
int cnt,i,num;
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	c=getchar();
	while(c!=-1&&c!='\n'){
		a[++cnt]=c;
		c=getchar();
	}
	d=a[1];b[++num]=d;
	for(i=2;i<=cnt;i++){
		if(a[i]==d){
			continue;
		}
		else{
			d=a[i];
			b[++num]=d;
		}
	}
	for(i=1;i<=num;i++){
		putchar(b[i]);
	}
	putchar('\n');
	fclose(stdin);fclose(stdout);
	return 0;
}
