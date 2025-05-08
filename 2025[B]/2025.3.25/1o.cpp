#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,k,op,n,m,cha,last;
map<int,map<int,map<int,int>>>M;
signed main(){
	freopen("1o.in","r",stdin);freopen("1o.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m;op=0;M.clear();
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				for(k=j+1;k<=m;k++){
					if((i^j)==k){
						M[i][j][k]=1;
					}
				}
			}
		}
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				for(k=j+1;k<=m;k++){
					if(M[i][j][k]==1){
						op++;
						printf("options:%lld\n",op);
						printf("a:%lld b:%lld c:%lld\n",i,j,k);
					}
				}
			}
		}
		//printf("options:%lld  m:%lld  ",op,m);cha=op-last;
	//	printf("cha:%lld\n",cha);last=op;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
