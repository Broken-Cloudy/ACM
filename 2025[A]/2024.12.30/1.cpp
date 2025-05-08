#include<iostream>
#include<cstdio>
#include<cmath>
#define int long long
using namespace std;
const long double pi=acosl(-1);
int T,i,j,k,n,m,ans[1600009];
struct complex{//自己写构造复数 
	long double x,y;
	complex(long double xx=0,long double yy=0){//这里不加零就会报错 
		x=xx;y=yy;//初始化 
	}
}a[1600009],b[1600009],c[1600009];
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
	long double NUM=num;
	complex Wn=complex(cosl(2.0l*pi/NUM),f*sinl(2.0l*pi/NUM));//Wn是单位根 
	complex w=complex(1.0L,0.0L);//w是幂 
	for(int i=0;i<num/2;i++,w=w*Wn){//这里的w相当于公式中的k
		a[i]=a1[i]+w*a2[i];
		a[i+(num/2)]=a1[i]-w*a2[i];//利用单位根的性质，O(1)得到另一部分
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=0;i<=8*n;i++){
			a[i].x=b[i].x=c[i].x=0;
			a[i].y=b[i].y=c[i].y=0;
		}
		for(i=1;i<=n;i++){
			scanf("%llf",&a[i].x);
			a[i+n].x=a[i].x;
		}
		for(i=1,j=n/2,k=1;i<=n/2;i++){
			if(i%2){
				b[i].x=b[n-i].x=j;
				j--;
			}
			else{
				b[i].x=b[n-i].x=k;
				k++;
			}
		}
		int num=1;m=n-1;n*=2;
		while(num<=n+m)num*=2;
		FFT(num,a,1); 
		FFT(num,b,1);
		for(i=0;i<=num;i++){
			c[i]=a[i]*b[i];
		}
		FFT(num,c,-1);
		long double NUM=num;
		for(i=0;i<=(n+m);i++)ans[i]=(int)(c[i].x/NUM+0.5L);n/=2;
		for(i=n+1;i<=n*2;i++){
			printf("%lld ",ans[i]);
		}
		//for(i=1;i<=9999;i++)cout<<50000000<<' ';
		printf("\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
