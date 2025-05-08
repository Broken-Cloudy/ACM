#include<bits/stdc++.h>
#define int long long
using namespace std;
char c[1000009];
int len,i;
bool f,ff,fff,f4,f5;//f是符号 ff表示数字是A fff表示数字是n
int A,n,a[100009],b[100009];
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	scanf("%s",c+1);
	len=strlen(c+1);
	for(i=6;i<=len;i++){
		if(c[i]=='^')continue;
		if(i==6){//第一项 
			if(c[i]=='-')f=1,ff=1;//负数 
			else if(c[i]=='x'){
				fff=1;A=1;
			}
			else if(c[i]>='0'&&c[i]<='9'){
				f=0;ff=1;
				A=A*10+(c[i]-'0');
			}
		}
		else{
			if(c[i]=='-'||c[i]=='+'){//本项结束 
				if(fff==0){//次数为0 
					a[0]=A;
					A=n=0;
					if(c[i]=='-')f=1;
					else f=0;
					ff=1;//开始输入系数
					fff=0; 
				}
				else if(fff==1&&n==0){//次数为1 
					a[1]=A;
					A=n=0;
					if(c[i]=='-')f=1;
					else f=0;
					ff=1;//开始输入系数
					fff=0; 
				}
				else{
					a[n]=A;
					A=n=0;
					if(c[i]=='-')f=1;
					else f=0;
					ff=1;//开始输入系数
					fff=0; 
				}
			}
			else if(c[i]=='x'){//开始输入次数 
				fff=1;
				if(A==0)A=1;
				if(f==1)A=-A;
			}
			else if(c[i]>='0'&&c[i]<='9'){
				if(fff==1){//输入次数 
					n=n*10+(c[i]-48);
				}
				else if(ff==1){//输入系数 
					A=A*10+(c[i]-48);
				}
			}
		}
	}
	if(fff==0){//次数为0 
		a[0]=A;
	}
	else if(fff==1&&n==0){//次数为1 
		a[1]=A;
	}
	else{
		a[n]=A;
		A=n=0;
		if(c[i]=='-')f=1;
		else f=0;
		ff=1;//开始输入系数
		fff=0; 
	}
	for(i=1;i<=100000;i++){
		if(a[i]!=0){
			b[i-1]=a[i]*i;
		}
	}
	cout<<"f'(x)=";
	for(i=100000;i>=0;i--){
		if(b[i]!=0){
			f5=1;
			if(b[i]!=1||b[i]==1&&i==0){
				if(b[i]>0&&f4==1){
					printf("+");
					printf("%lld",b[i]);
				}
				else if(b[i]>0&&f4==0){
					printf("%lld",b[i]);
					f4=1;
				}
				else{
					printf("%lld",b[i]);
					f4=1;
				}
			}
			else{
				if(f4==1){
					printf("+");
				}
				else if(f4==0){
					f4=1;
				}
			}
			if(i!=0&&i!=1){
				printf("x^");
				printf("%lld",i);
			}
			else if(i==1){
				printf("x");
			}
			else{
				//无 
			}
		}
	}
	if(f5==0)printf("0");
	fclose(stdin);fclose(stdout);
	return 0;
}
