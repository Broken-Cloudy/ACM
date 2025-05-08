#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
struct nod{
	long long matrix[3][3];
};
const long long inf=1e9+7;
long long n[1000010],m[1000010],cnt1,cnt2,a,b,c,d,r,i,j;
char ch;
nod D,A,B,ANS;//E单位阵 
inline void clear(nod &x){
	x.matrix[1][1]=x.matrix[2][2]=1;x.matrix[1][2]=x.matrix[2][1]=0;
	return;
}
inline void Pre(){
	for(int i=1;i<=cnt1/2;i++){
		swap(n[i],n[cnt1-i+1]);
	}
	for(int i=1;i<=cnt2/2;i++){
		swap(m[i],m[cnt2-i+1]);
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
inline nod ksm(nod A,int p[],int plen){
	int i;
	nod E,kk,ans;clear(E);
	for(i=1;i<=plen;i++){
		if(i!=plen){
			if(p[i]==9){kk=A;E=kk*E;kk=kk*kk;kk=kk*kk;kk=kk*kk;E=kk*E;}
			else if(p[i]==8){kk=A;kk=kk*kk;kk=kk*kk;kk=kk*kk;E=kk*E;}
			else if(p[i]==7){kk=A;E=kk*E;kk=kk*kk;E=kk*E;kk=kk*kk;E=kk*E;}
			else if(p[i]==6){kk=A;kk=kk*kk;E=kk*E;kk=kk*kk;E=kk*E;}
			else if(p[i]==5){kk=A;E=kk*E;kk=kk*kk;kk=kk*kk;E=kk*E;}
			else if(p[i]==4){kk=A;kk=kk*kk;kk=kk*kk;E=kk*E;}
			else if(p[i]==3){kk=A;E=kk*E;kk=kk*kk;E=kk*E;}
			else if(p[i]==2){kk=A;kk=kk*kk;E=kk*E;}
			else if(p[i]==1){kk=A;E=kk*E;}
			A=A*A;kk=A;A=A*A;A=A*A;A=A*kk;
		}
		else{
			p[i]--;
			if(p[i]==8){kk=A;kk=kk*kk;kk=kk*kk;kk=kk*kk;E=kk*E;}
			else if(p[i]==7){kk=A;E=kk*E;kk=kk*kk;E=kk*E;kk=kk*kk;E=kk*E;}
			else if(p[i]==6){kk=A;kk=kk*kk;E=kk*E;kk=kk*kk;E=kk*E;}
			else if(p[i]==5){kk=A;E=kk*E;kk=kk*kk;kk=kk*kk;E=kk*E;}
			else if(p[i]==4){kk=A;kk=kk*kk;kk=kk*kk;E=kk*E;}
			else if(p[i]==3){kk=A;E=kk*E;kk=kk*kk;E=kk*E;}
			else if(p[i]==2){kk=A;kk=kk*kk;E=kk*E;}
			else if(p[i]==1){kk=A;E=kk*E;}
		}
	}
	ans=E*A;
	return ans;
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
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
	if(m[1]==0&&cnt2==1)clear(A);
	else A=ksm(A,m,cnt2);
	D=A*B;//再算D^(n-1) 
	if(n[1]==0&&cnt1==1)clear(D);
	else D=ksm(D,n,cnt1);
	ANS=D*A;
	long long ans=(ANS.matrix[1][1]+inf)+(ANS.matrix[1][2]+inf)%inf;
	ans%=inf;
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
