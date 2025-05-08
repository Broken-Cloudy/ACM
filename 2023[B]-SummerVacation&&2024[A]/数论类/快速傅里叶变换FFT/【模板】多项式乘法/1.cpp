//����ʹ������ͷ�ļ� 
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,i;
const double pi=acos(-1);
struct complex{//�Լ�д���츴�� 
	double x,y;
	complex(double xx=0,double yy=0){//���ﲻ����ͻᱨ�� 
		x=xx;y=yy;
	}
}a[2000010],b[2000010];
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
	complex a1[num/2],a2[num/2]; 
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
	cin>>n>>m;
	for(i=0;i<=n;i++)scanf("%lf",&a[i].x);//ʵ������ 
	for(i=0;i<=m;i++)scanf("%lf",&b[i].x);//ʵ������ 
	int num=1;
	while(num<=n+m)num*=2;
	FFT(num,a,1); 
	FFT(num,b,1); 
	for(i=0;i<=num;i++){
		a[i]=a[i]*b[i];
	}
	FFT(num,a,-1);
	for(i=0;i<=(n+m);i++)printf("%d ",(int)(a[i].x/num+0.5));//�������� 
	//���������Ƶ��Ĺ�ʽ�����ﻹҪ����n 
	fclose(stdin);fclose(stdout);
	return 0;
}
