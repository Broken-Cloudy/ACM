//����ʹ������ͷ�ļ� 
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
char s1[4000010],s2[4000010];
int n,m,i,j;
int ans[4000010];
char c;
const double pi=acos(-1);
struct complex{//�Լ�д���츴�� 
	double x,y;
	complex(double xx=0,double yy=0){//���ﲻ����ͻᱨ�� 
		x=xx;y=yy;
	}
}a[4000010],b[4000010];
complex operator +(complex a,complex b){
	return complex(a.x+b.x,a.y+b.y);
}
complex operator -(complex a,complex b){
	return complex(a.x-b.x,a.y-b.y);
}
complex operator *(complex a,complex b){
	return complex(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
}
void FFT(int num,complex *a,int f){
	if(num==1)return;//ֻ��һ��
	complex a1[num/2+1],a2[num/2+1];//��������δ֪���� 
	for(int i=0;i<=num;i+=2){//��ż���� 
		a1[i>>1]=a[i];a2[i>>1]=a[i+1];
	}
	FFT(num/2,a1,f);
	FFT(num/2,a2,f);
	complex Wn=complex(cos(2.0*pi/num),f*sin(2.0*pi/num));//Wn�ǵ�λ�� 
	complex w=complex(1,0);//w���� 
	for(int i=0;i<num/2;i++,w=w*Wn){//�����w�൱�ڹ�ʽ�е�k
		a[i]=a1[i]+w*a2[i];
		a[i+(num/2)]=a1[i]-w*a2[i];//���õ�λ�������ʣ�O(1)�õ���һ����
	}
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	scanf("%s",s1);scanf("%s",s2);
	n=strlen(s1)-1;m=strlen(s2)-1;
	for(i=0;i<=n;i++)a[i].x=s1[i]-'0';//ʵ������ 
	for(i=0;i<=m;i++)b[i].x=s2[i]-'0';//ʵ������ 
	int num=1;
	while(num<=n+m)num*=2;
	FFT(num,a,1); 
	FFT(num,b,1); 
	for(i=0;i<=num;i++){
		a[i]=a[i]*b[i];
	}
	FFT(num,a,-1);
	for(i=(n+m),j=0;i>=0&&j<=(n+m);i--,j++){
		ans[j]+=(int)(a[i].x/num+0.5);//���������Ƶ��Ĺ�ʽ�����ﻹҪ����num 
		ans[j+1]+=ans[j]/10;
		ans[j]%=10;
	}
	if(ans[n+m+1]!=0)printf("%d",ans[n+m+1]);
	for(i=(n+m);i>=0;i--){
		c=ans[i]+'0';
		putchar(c);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
