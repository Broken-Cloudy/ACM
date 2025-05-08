#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,a[12][12],FF;
map<int,int>M;
int check(int x,int y){
	int i,j;
	int F=1;
	M.clear();
	for(i=x;i<=x+2;i++){
		for(j=y;j<=y+2;j++){
			M[a[i][j]]=1;
		}
	}
	for(j=1;j<=9;j++){
		if(M[j]==0){
			F=0;
			break;
		}
	}
	return F;
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		FF=1;
		for(i=1;i<=9;i++)for(j=1;j<=9;j++)scanf("%lld",&a[i][j]);
		for(i=1;i<=9;i++){
			M.clear();
			for(j=1;j<=9;j++){
				M[a[i][j]]=1;
			}
			for(j=1;j<=9;j++){
				if(M[j]==0){
					FF=0;
					break;
				}
			}
		}
		for(i=1;i<=9;i++){
			M.clear();
			for(j=1;j<=9;j++){
				M[a[j][i]]=1;
			}
			for(j=1;j<=9;j++){
				if(M[j]==0){
					FF=0;
					break;
				}
			}
		}
		for(i=1;i<=9;i+=3){
			for(j=1;j<=9;j+=3){
				if(check(i,j)==0){
					FF=0;
					break;
				}
			}
			if(FF==0)break;
		}
		printf("%lld\n",FF);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
