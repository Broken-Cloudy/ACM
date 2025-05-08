#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1099][1099],i,j,cnt;
bool f[1099][1099];
char c,k[3009];
char work(long long z){
	if(z==n+m-1)return a[n][m]+'a';
	long long sma=99;
	long long x,y;
	if(z>m){
		x=z-m+1,y=m;
		while(x<=n&&y>=1){
			if(f[x-1][y]==1||f[x][y-1]==1)sma=min(a[x][y],sma);
			x++;y--;
		}
		x=z-m+1,y=m;
		while(x<=n&&y>=1){
			if(a[x][y]==sma&&(f[x-1][y]==1||f[x][y-1]==1)){
				f[x][y]=1;
			}
			x++;y--;
		}
	}
	else{
		x=1,y=z;
		while(x<=n&&y>=1){
			if(f[x-1][y]==1||f[x][y-1]==1)sma=min(a[x][y],sma);
			x++;y--;
		}
		x=1,y=z;
		while(x<=n&&y>=1){
			if(a[x][y]==sma&&(f[x-1][y]==1||f[x][y-1]==1)){
				f[x][y]=1;
			}
			x++;y--;
		}
	}
	return (sma+'a');
}
int main(){
    freopen("2.in","r",stdin);freopen("2.out","w",stdout);
    cin>>n>>m;f[1][1]=1;
    for(i=1;i<=n;i++){
    	getchar();
    	for(j=1;j<=m;j++){
    		c=getchar();
    		a[i][j]=c-'a';
		}
	}
	k[++cnt]=a[1][1]+'a';
	for(i=2;i<=n+m-1;i++){
		k[++cnt]=work(i);
	}
	for(i=1;i<=cnt;i++){
		putchar(k[i]);
	}
	putchar('\n');
    fclose(stdin);fclose(stdout);
    return 0;
}
