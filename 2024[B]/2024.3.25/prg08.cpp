#include<bits/stdc++.h>
using namespace std;
int i,len,j;
string s[15];
char a[108][108];
int main(){
	//string���� 
	s[1]="January";s[2]="February";s[3]="March";s[4]="April";
	s[5]="May";s[6]="June";s[7]="July";s[8]="August";
	s[9]="September";s[10]="October";s[11]="November";s[12]="December";
	for(i=1;i<=12;i++)cout<<s[i]<<endl;//��� 
	
	//�ַ�����
	for(i=1;i<=12;i++){//��string���·ݸ��Ƶ�char 
		len=s[i].length();
		for(j=0;j<len;j++){
			a[i][j]=s[i][j];
		}
	}
	for(i=1;i<=12;i++)puts(a[i]);//��� 
	
	//��ָ��
	char (*p)[108]=a;
	for(i=1;i<=12;i++)puts(*(p+i));
	
	//ָ������
	char *t[108][108];
	for(i=1;i<=12;i++){//ȡַ 
		len=s[i].length();
		for(j=0;j<len;j++){
			t[i][j]=&a[i][j];
		}
	} 
	for(i=1;i<=12;i++)puts(*(t[i]));
	
	//ָ��ָ���ָ��
	char *r[108][108];
	for(i=1;i<=12;i++){//ȡַ 
		len=s[i].length();
		for(j=0;j<len;j++){
			r[i][j]=&*t[i][j];
		}
	}
	for(i=1;i<=12;i++)puts(*(r[i]));
	return 0;
}
