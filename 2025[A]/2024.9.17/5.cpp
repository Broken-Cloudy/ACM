#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=1e9+7;
int n,f[10009][2][2][2][2],i;
void F(int w,int x,int y,int z,int k){//2
	if(w)f[i][w][x][y][z]+=f[i-1][0][x][y][z]*1;
	if(x)f[i][w][x][y][z]+=f[i-1][w][0][y][z]*1;
	if(y)f[i][w][x][y][z]+=f[i-1][w][x][0][z]*1;
	if(z)f[i][w][x][y][z]+=f[i-1][w][x][y][0]*1;
	f[i][w][x][y][z]+=f[i-1][w][x][y][z]*(22+k);
	f[i][w][x][y][z]%=P;
}
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n;f[0][0][0][0][0]=1;
	for(i=1;i<=n;i++){
		F(0,0,0,0,0);
		F(1,0,0,0,1);
		F(0,0,1,0,1);
		F(0,1,0,0,1);
		F(0,0,0,1,1);
		F(1,1,0,0,2);
		F(1,0,1,0,2);
		F(1,0,0,1,2);
		F(0,1,1,0,2);
		F(0,1,0,1,2);
		F(0,0,1,1,2);
		F(1,1,1,0,3);
		F(0,1,1,1,3);
		F(1,1,0,1,3);
		F(1,0,1,1,3);
		F(1,1,1,1,4);
	}
	cout<<f[n][1][1][1][1]%P<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
