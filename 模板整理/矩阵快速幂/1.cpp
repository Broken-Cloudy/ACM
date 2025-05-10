#include<bits/stdc++.h>
using namespace std;
int n,i,j;
long long k;
const long long inf=1e9+7;
struct nod{
	long long matrix[109][109];//[行][列] 
};
nod a,E;//E是单位阵 
nod operator *(const nod &x,const nod &y){//定义矩阵乘法 
	nod ans;
	int i,j,k;
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)ans.matrix[i][j]=0;//!!!
	for(i=1;i<=n;i++){//ans的行 
		for(j=1;j<=n;j++){//ans的列 
			for(k=1;k<=n;k++){
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
	cin>>n>>k;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%lld",&a.matrix[i][j]);
		}
	}
	for(i=1;i<=n;i++){//E
		E.matrix[i][i]=1;
	}
	while(k>1){
		if(k%2==0){
			a=a*a;
			k/=2;
		}
		else{
			E=E*a;
			k--;
		}
	}
	a=a*E;
	if(k==0){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(j==n)printf("%lld\n",E.matrix[i][j]);
				else printf("%lld ",E.matrix[i][j]);
			}
		}
	}
	else{
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(j==n)printf("%lld\n",a.matrix[i][j]);
				else printf("%lld ",a.matrix[i][j]);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
