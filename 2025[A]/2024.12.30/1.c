#include<stdio.h>
#include<math.h>
#define int long long
const long double pi=3.141592653589793238462643383279;
int T,i,j,k,n,m,ans[1600009];
struct complex{//�Լ�д���츴�� 
	long double x,y;
	complex(long double xx=0,long double yy=0){//���ﲻ����ͻᱨ�� 
		x=xx;y=yy;//��ʼ�� 
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
	if(num==1)return;//ֻ��һ��
	complex a1[num/2+1],a2[num/2+1]; 
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
		for(i=0;i<=(n+m);i++)ans[i]=(int)(c[i].x/num+0.5);n/=2;
		for(i=n+1;i<=n*2;i++){
			printf("%lld ",ans[i]);
		}
		printf("\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
