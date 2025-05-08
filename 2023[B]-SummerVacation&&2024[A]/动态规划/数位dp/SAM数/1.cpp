#include<bits/stdc++.h>
using namespace std;
const long long inf=1e9+7;
long long n;
struct nod{
	long long matrix[12][12];
};
nod E,D,a;
int i,j;
long long ans;
nod operator *(const nod &x,const nod &y){
	nod ans;
	int i,j,k;
	for(i=1;i<=10;i++)for(j=1;j<=10;j++)ans.matrix[i][j]=0;
	for(i=1;i<=10;i++){//位数矩阵 [i][j]
		for(j=1;j<=10;j++){
			for(k=1;k<=10;k++){
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
	cin>>n;
	if(n==1)cout<<10<<endl;
	else{
		for(i=1;i<=10;i++){//单位阵 
			E.matrix[i][i]=1;
		}
		for(i=2;i<=10;i++){//构造行a
			a.matrix[1][i]=1;
		}
		for(i=1;i<=10;i++){//构造矩阵 
			for(j=i-2;j<=i+2;j++){
				if(j>=1&&j<=10){
					D.matrix[i][j]=1;
				}
			}
		}
		n--;
		while(n>1){//快速幂 
			if(n%2==0){
				D=D*D;
				n/=2;
			}
			else if(n%2==1){
				E=E*D;
				n--;
			}
		}
		D=D*E;
		a=a*D;
		for(i=1;i<=10;i++){
			ans+=a.matrix[1][i];
			ans%=inf;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
