#include<iostream>
#include<cstdio>
using namespace std;
const int INF=1e9+7;
char a[1200],b[1200];
int n,m,match[255][255],i,j,f[255][255];
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	match['A']['A']=5;match['C']['C']=5;match['G']['G']=5;match['T']['T']=5;
	match['A']['C']=-1;match['C']['T']=-2;match['G']['T']=-2;match['T']['A']=-1;
	match['A']['T']=-1;match['C']['G']=-3;match['G']['C']=-3;match['T']['G']=-2;
	match['A']['G']=-2;match['C']['A']=-1;match['G']['A']=-2;match['T']['C']=-2;
	match['A']['-']=-3;match['C']['-']=-4;match['G']['-']=-2;match['T']['-']=-1;
	match['-']['A']=-3;match['-']['C']=-4;match['-']['G']=-2;match['-']['T']=-1;
	cin>>n;scanf("%s",a+1);
	cin>>m;scanf("%s",b+1);
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			f[i][j]=-INF;
		}
	}
	f[0][0]=0;
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			if(i-1>=0&&j-1>=0)f[i][j]=max(f[i][j],f[i-1][j-1]+match[a[i]][b[j]]);
			if(i-1>=0)f[i][j]=max(f[i][j],f[i-1][j]+match[a[i]]['-']);
			if(j-1>=0)f[i][j]=max(f[i][j],f[i][j-1]+match['-'][b[j]]);
		}
	}
	cout<<f[n][m]<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
