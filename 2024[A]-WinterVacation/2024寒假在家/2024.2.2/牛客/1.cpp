#include<bits/stdc++.h>
using namespace std;
int T,n,len,i,k1,k2;
char c[98];
bool f1,f2;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		cin>>n;f1=0;f2=0;k1=0;k2=0;
		memset(c,0,sizeof(c));
		scanf("%s",c+1);
		int len=strlen(c+1);
		for(i=1;i<=len;i++){
			if(c[i]=='D'&&k1==0)k1++;
			if(c[i]=='F'&&k1==1)k1++;
			if(c[i]=='S'&&k1==2)k1++;
			if(c[i]=='d'&&k2==0)k2++;
			if(c[i]=='f'&&k2==1)k2++;
			if(c[i]=='s'&&k2==2)k2++;
			if(k1==3)f1=1;
			if(k2==3)f2=1;
		}
		if(f1==0)printf("0 ");
		else printf("1 ");
		if(f2==0)printf("0\n");
		else printf("1\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
