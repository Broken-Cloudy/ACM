//不能使用万能头文件 
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
struct complex{//自己写构造复数 
	double x,y;
	complex(double xx=0,double yy=0){//这里不加零就会报错 
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
	if(num==1)return;//只有一项
	complex a1[num/2+1],a2[num/2+1];//这里会出现未知错误 
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
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	scanf("%s",s1);scanf("%s",s2);
	n=strlen(s1)-1;m=strlen(s2)-1;
	for(i=0;i<=n;i++)a[i].x=s1[i]-'0';//实数部分 
	for(i=0;i<=m;i++)b[i].x=s2[i]-'0';//实数部分 
	int num=1;
	while(num<=n+m)num*=2;
	FFT(num,a,1); 
	FFT(num,b,1); 
	for(i=0;i<=num;i++){
		a[i]=a[i]*b[i];
	}
	FFT(num,a,-1);
	for(i=(n+m),j=0;i>=0&&j<=(n+m);i--,j++){
		ans[j]+=(int)(a[i].x/num+0.5);//按照我们推导的公式，这里还要除以num 
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
