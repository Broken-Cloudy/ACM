#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const double pi=acos(-1);
struct complex{
	double x,y;
	complex(double xx=0,double yy=0){
		x=xx;y=yy;
	}
};
complex a[4000009],b[4000009];
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
	if(num==1)return;//只有一项
	complex a1[num/2+1],a2[num/2+1]; 
	for(int i=0;i<=num;i+=2){//奇偶分类 
		a1[i>>1]=a[i];a2[i>>1]=a[i+1];
	}
	FFT(num/2,a1,f);
	FFT(num/2,a2,f);
	complex Wn=complex(cos(2.0*pi/num),f*sin(2.0*pi/num));//Wn是单位根 
	complex w=complex(1,0);//w是幂 
	for(int i=0;i<num/2;i++,w=w*Wn){//这里的w相当于公式中的k
		a[i]=a1[i]+w*a2[i];
		a[i+(num/2)]=a1[i]-w*a2[i];//利用单位根的性质，O(1)得到另一部分
	}
}
int n,m,i;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
