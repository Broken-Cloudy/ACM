#include<iostream>
#include<cstdio>
#pragma GCC optimize(2)
using namespace std;
struct nod{
	long long matrix[3][3];
};
const long long inf=1e9+7;
long long n[1000010],m[1000010],cnt1,cnt2,a,b,c,d,r,i,j;
char ch;
nod E,C,D,A,B,ANS;
inline void Pre(){
	for(int i=1;i<=cnt1/2;i++){
		swap(n[i],n[cnt1-i+1]);
	}
	for(int i=1;i<=cnt2/2;i++){
		swap(m[i],m[cnt2-i+1]);
	}
	for(int i=1;i<=2;i++){//多弄几个单位矩阵 
		E.matrix[i][i]=1;
		C.matrix[i][i]=1;
	}
	A.matrix[1][1]=a;A.matrix[1][2]=b;A.matrix[2][2]=1;//m
	B.matrix[1][1]=c;B.matrix[1][2]=d;B.matrix[2][2]=1;//n
	int i=1;
	while(m[i]==0)i++;//算m-1 
	for(int j=1;j<=i;j++){
		if(i==j){
			if(m[j]==1&&j==cnt2)cnt2--;
			m[j]-=1;
		}
		else m[j]=9;
	}
	i=1;
	while(n[i]==0)i++;//算n-1 
	for(int j=1;j<=i;j++){
		if(i==j){
			if(n[j]==1&&j==cnt1)cnt1--;
			n[j]-=1;
		}
		else n[j]=9;
	}
}
inline nod operator *(const nod &x,const nod &y){//
	nod ans;
	int i,j,k;
	//记得初始化
	ans.matrix[0][0]=0;ans.matrix[0][1]=0;ans.matrix[0][2]=0;
	ans.matrix[1][0]=0;ans.matrix[1][1]=0;ans.matrix[1][2]=0;
	ans.matrix[2][0]=0;ans.matrix[2][1]=0;ans.matrix[2][2]=0;
	for(i=1;i<=2;i++){//ans的行 
		for(j=1;j<=2;j++){//ans的列 
			for(k=1;k<=2;k++){
				ans.matrix[i][j]+=x.matrix[i][k]*y.matrix[k][j];
				ans.matrix[i][j]%=inf;
			}
			ans.matrix[i][j]%=inf;
		}
	}
	return ans;
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	ch=getchar();
	while(ch!=' '){
		n[++cnt1]=ch-48;
		ch=getchar();
	}
	ch=getchar();
	while(ch!=' '){
		m[++cnt2]=ch-48;
		ch=getchar();
	}
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	Pre();
	if(cnt2==0)A=E;
	while(cnt2!=0){//m-1
		if(cnt2==1&&m[1]==1)break;
		if(m[1]%2==0){
			A=A*A;r=0;
			for(i=cnt2;i>=1;i--){
				r=r*10+m[i];
				if(r%2==1){
					m[i]=r/2;
					r=1;
				}
				else{
					m[i]=r/2;
					r=0;
				}
			}
			if(m[cnt2]==0)cnt2--;
		}
		else{
			E=E*A;A=A*A;m[1]-=1;r=0;
			for(i=cnt2;i>=1;i--){
				r=r*10+m[i];
				if(r%2==1){
					m[i]=r/2;
					r=1;
				}
				else{
					m[i]=r/2;
					r=0;
				}
			}
			if(m[cnt2]==0)cnt2--;
		}
	}
	A=A*E;
	D=A*B;//再算D^(n-1) 
	if(cnt1==0)D=C;
	while(cnt1!=0){//n-1
		if(cnt1==1&&n[1]==1)break;
		if(n[1]%2==0){
			D=D*D;r=0;
			for(i=cnt1;i>=1;i--){
				r=r*10+n[i];
				if(r%2==1){
					n[i]=r/2;
					r=1;
				}
				else{
					n[i]=r/2;
					r=0;
				}
			}
			if(n[cnt1]==0)cnt1--;
		}
		else{
			C=C*D;D=D*D;n[1]-=1;r=0;
			for(i=cnt1;i>=1;i--){
				r=r*10+n[i];
				if(r%2==1){
					n[i]=r/2;
					r=1;
				}
				else{
					n[i]=r/2;
					r=0;
				}
			}
			if(n[cnt1]==0)cnt1--;
		}
	}
	D=C*D;
	ANS=D*A;
	long long ans=(ANS.matrix[1][1]+inf)+(ANS.matrix[1][2]+inf)%inf;
	ans%=inf;
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
