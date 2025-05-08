#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,j,s1,s2,m1,m2,x,y,M1[1009][1009],M2[1009][1009];
int a[1009][1009],b[1009][1009],f[1009][1009];
set<int>ver1,ver2;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&s1,&s2);
		for(i=0;i<=n;i++){
			for(j=1;j<=n;j++)a[i][j]=a[j][i]=0;
			f[i][0]=M1[i][0]=M2[i][0]=0;
		}
		scanf("%lld",&m1);scanf("%lld",&m2);
		for(i=1;i<=m1;i++){
			scanf("%lld%lld",&x,&y);
			M1[x][++M1[x][0]]=y;M1[y][++M1[y][0]]=x;
			a[x][y]=a[y][x]=1;
		}
		for(i=1;i<=m2;i++){
			scanf("%lld%lld",&x,&y);
			M2[x][++M2[x][0]]=y;M2[y][++M2[y][0]]=x;
			b[x][y]=b[y][x]=1;
		}
		ver1.clear();ver2.clear();
		f[0][++f[0][0]]=s1;ver1.insert(s1);
		for(i=1;i<=2000;i++){//走2000步 
			if(ver2.empty()){
				for(auto t:ver1){
					for(j=1;j<=M1[t][0];j++)ver2.insert(M1[t][j]);
				}
				ver1.clear();
				for(auto t:ver2)f[i][++f[i][0]]=t;
			}
			else{
				for(auto t:ver2){
					for(j=1;j<=M1[t][0];j++)ver1.insert(M1[t][j]);
				}
				ver2.clear();
				for(auto t:ver1)f[i][++f[i][0]]=t;
			}
		}
		ver1.clear();ver2.clear();ver1.insert(s2);
		for(i=1;i<=2000;i++){//走2000步 
			if(ver2.empty()){
				for(auto t:ver1){
					for(j=1;j<=M1[t][0];j++)ver2.insert(M1[t][j]);
				}
				ver1.clear();
				for(auto t:ver2)f[i][++f[i][0]]=t;
			}
			else{
				for(auto t:ver2){
					for(j=1;j<=M1[t][0];j++)ver1.insert(M1[t][j]);
				}
				ver2.clear();
				for(auto t:ver1)f[i][++f[i][0]]=t;
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
