#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,L,R,a[509],i,j,k,len,c1[509],c0[509],C1,C0;
int f[509][509];
char c;
int abss(int x){
	return max(x,-x);
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>L>>R;getchar();
	for(i=1;i<=n;i++){
		c=getchar();
		a[i]=c-'0';
	}
	for(i=1;i<=n;i++){
		if(a[i]==1){
			c1[i]=c1[i-1]+1;
			c0[i]=c0[i-1];
		}
		else{
			c1[i]=c1[i-1];
			c0[i]=c0[i-1]+1;
		}
	}
	for(len=2;len<=n;len++){
		for(i=1;i<=n-len+1;i++){
			j=i+len-1;
			for(k=i;k<j;k++){
				C0=(c0[k]-c0[i-1]);//×ó±ß 
				C1=(c1[j]-c1[(k+1)-1]);//ÓÒ±ß
				if(abss(C0-C1)>=L&&abss(C0-C1)<=R){
					f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+1);
				}
			}
		}
	}
	cout<<f[1][n]<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
