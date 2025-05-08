#include<iostream>
#include<cstdio>
using namespace std;
long long x,T,k,D,i,ans,j;
const long long inf=1e9+7;
struct nod{
	long long matrix[4][4];//[行][列] 
};
nod a,E;//E是单位阵 
nod operator *(const nod &x,const nod &y){//定义矩阵乘法 
	nod ans;
	int i,j,k;
	for(i=1;i<=2;i++)for(j=1;j<=2;j++)ans.matrix[i][j]=0;//!!!
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
	cin>>T;
	for(long long o=1;o<=T;o++){
		scanf("%lld",&x);
		if(x==0){
			printf("%lld\n",0);
		}
		else if(x==1){
			printf("%lld\n",2);
		}
		else if(x==2){
			printf("%lld\n",3);
		}
		else{
			for(i=1;i<=2;i++)for(j=1;j<=2;j++)E.matrix[i][j]=0;
			for(i=1;i<=2;i++)for(i=1;i<=2;i++)E.matrix[i][i]=1;
			a.matrix[1][1]=1;a.matrix[1][2]=1;a.matrix[2][1]=1;a.matrix[2][2]=0;
			x-=2;
			while(x>1){
				if(x%2==0){
					a=a*a;
					x/=2;
				}
				else{
					E=E*a;
					x--;
				}
			}
			a=a*E;
			ans=3*a.matrix[1][1];
			ans%=inf;
			ans+=2*a.matrix[1][2];
			ans%=inf;
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
