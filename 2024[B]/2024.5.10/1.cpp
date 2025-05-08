#include<bits/stdc++.h>
using namespace std;
int getin(){
	int a=0;
	bool b=0;//·ûºÅÅÐ¶Ï
	char c;
	c=getchar(); 
	if(c=='-')b=1;
	else a=c-48;
	c=getchar();
	while(c>='0'&&c<='9'){//ÅÐ¶ÏÎªÊý×ÖÊ± 
		a=a*10+c-48;
		c=getchar();
	}
	if(b==1)return -a;
	else return a;
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	int a;
	a=getin();
	cout<<a<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
