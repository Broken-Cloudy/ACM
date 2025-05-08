#include<bits/stdc++.h>
using namespace std;
int i,len,j;
string s[15];
char a[108][108];
int main(){
	//string类型 
	s[1]="January";s[2]="February";s[3]="March";s[4]="April";
	s[5]="May";s[6]="June";s[7]="July";s[8]="August";
	s[9]="September";s[10]="October";s[11]="November";s[12]="December";
	for(i=1;i<=12;i++)cout<<s[i]<<endl;//输出 
	
	//字符数组
	for(i=1;i<=12;i++){//将string的月份复制到char 
		len=s[i].length();
		for(j=0;j<len;j++){
			a[i][j]=s[i][j];
		}
	}
	for(i=1;i<=12;i++)puts(a[i]);//输出 
	
	//行指针
	char (*p)[108]=a;
	for(i=1;i<=12;i++)puts(*(p+i));
	
	//指针数组
	char *t[108][108];
	for(i=1;i<=12;i++){//取址 
		len=s[i].length();
		for(j=0;j<len;j++){
			t[i][j]=&a[i][j];
		}
	} 
	for(i=1;i<=12;i++)puts(*(t[i]));
	
	//指向指针的指针
	char *r[108][108];
	for(i=1;i<=12;i++){//取址 
		len=s[i].length();
		for(j=0;j<len;j++){
			r[i][j]=&*t[i][j];
		}
	}
	for(i=1;i<=12;i++)puts(*(r[i]));
	return 0;
}
