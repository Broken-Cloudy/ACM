#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c,T,n,i,j,f[109][9],aa[10009],bb[10009];
int ff=0;
int wei(int x){
	if(x>=1&&x<=9)return 1;
	else if(x>=10&&x<=99)return 2;
	else return 3;
}
int minn(int x,int y){
	return min(x,y);
}
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>T;
	for(i=1;i<=100;i++){
		if(i>=1&i<=9){
			for(j=1;j<=7;j++){
				f[i][j]=f[i][j-1]*10+i;
			}
		}
		else if(i>=10&&i<=99){
			f[i][1]=i/10;
			f[i][2]=i;
			f[i][3]=(i*10)+(i/10);
			f[i][4]=(i*100)+i;
			f[i][5]=(i*1000)+(i*10)+(i/10);
			f[i][6]=(i*10000)+(i*100)+i;
			f[i][7]=(i*100000)+(i*1000)+(i*10)+(i/10);
		}
		else{
			f[100][1]=1;f[100][2]=10;f[100][3]=100;
			f[100][4]=1001;f[100][5]=10010;f[100][6]=100100;f[100][7]=1001001;
		}
	}
	for(int o=1;o<=T;o++){
		scanf("%lld",&n);ff=0;
		for(a=1;a<=10000;a++){
			for(i=1;i<=7;i++){
				b=a*n-f[n][i];
				if(i==(a*wei(n)-b)){
					if(b>=1&&b<=minn(a*n,10000)){
						ff++;
						aa[ff]=a;bb[ff]=b;
					}
				}
			}
		}
		printf("%lld\n",ff);
		for(i=1;i<=ff;i++){
			printf("%lld %lld\n",aa[i],bb[i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
