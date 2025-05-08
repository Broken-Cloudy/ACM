#include<bits/stdc++.h>
#define int long long
using namespace std;
char a[1000009],s[109];
bool f=0,ff=0,fff=0,ffff=0;
int i,cnt,k,r;
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	scanf("%s",a+1);
	int len=strlen(a+1);
	cout<<"f'(x)=";
	i=6;
	if(i==6){
		if(a[i]=='-'){
			f=1;//负数 
		}
		else if(a[i]>='0'&&a[i]<='9'){
			k=k*10+a[i]-48;
		}
		else{
			k=1;
			ff=1;//开始输入次数
		}
	}
	for(i=7;i<=len;i++){
		if(a[i]=='^')continue;
		else if(a[i]=='+'||a[i]=='-'){
			ffff=1;//输出过数字 
			if(ff!=0||r!=0){
				if(f==1)cout<<'-',fff=1;
				else if(f==0&&fff==1)cout<<'+';
				else if(f==0&&fff==0){
					fff=1;
				}
			}
			if(a[i]=='+')f=0;
			else f=1;
			if(ff==0&&r==0){//纯系数 
				ff=0;r=0;k=0; 
			}
			else if(ff==1&&r==0){//一次项 
				cout<<k;
				ff=0;r=0;k=0; 
			}
			else if(ff==1&&r==2){//二次项 
				cout<<k*2<<'x';
				ff=0;r=0;k=0; 
			}
			else{
				cout<<k*r<<'x'<<'^'<<r-1;
				ff=0;r=0;k=0; 
			}
		}
		else if(a[i]=='x'){
			if(k==0)k=1;
			ff=1;//开始输入次数
			continue; 
		}
		else if(a[i]>='0'&&a[i]<='9'){
			if(ff==0){
				k=k*10+a[i]-48;
			}
			else{
				r=r*10+a[i]-48;
			}
		}
	}
	if(ffff==0){
		if(ff!=0||r!=0){
			if(f==1)cout<<'-';
			else if(f==0&&fff==1)cout<<'+';
			else if(f==0&&fff==0){
				fff=1;
			}
		}
		if(a[i]=='+')f=0;
		else f=1;
		if(ff==0&&r==0){//纯系数 
			ff=0;r=0;k=0; 
			cout<<0;
		}
		else if(ff==1&&r==0){//一次项 
			cout<<k;
			ff=0;r=0;k=0; 
		}
		else if(ff==1&&r==2){//二次项 
			cout<<k*2<<'x';
			ff=0;r=0;k=0; 
		}
		else{
			cout<<k*r<<'x'<<'^'<<r-1;
			ff=0;r=0;k=0; 
		}
	}
	else{
		if(ff!=0||r!=0){
				if(f==1)cout<<'-';
				else if(f==0&&fff==1)cout<<'+';
				else if(f==0&&fff==0){
					fff=1;
				}
			}
			if(a[i]=='+')f=0;
			else f=1;
			if(ff==0&&r==0){//纯系数 
				ff=0;r=0;k=0; 
			}
			else if(ff==1&&r==0){//一次项 
				cout<<k;
				ff=0;r=0;k=0; 
			}
			else if(ff==1&&r==2){//二次项 
				cout<<k*2<<'x';
				ff=0;r=0;k=0; 
			}
			else{
				cout<<k*r<<'x'<<'^'<<r-1;
				ff=0;r=0;k=0; 
			}
	}
	cout<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
