#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,k,op,n,m,cha,last,p,q,r,s;
map<int,map<int,map<int,map<int,int>>>>M;
signed main(){
	freopen("1o.in","r",stdin);freopen("1o.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m;
		op=0;M.clear();
		for(p=0;p<=n;p++){
			for(q=p+1;q<=n;q++){
				for(r=0;r<=m;r++){
					for(s=r+1;s<=m;s++){
						if(p!=q&&p!=r&&p!=s&&q!=r&&q!=s&&r!=s){
							if((p^q)==(r^s)){
								M[p][q][r][s]=1;
							}
						}
					}
				}
			}
		}
		for(p=0;p<=n;p++){
			for(q=0;q<=n;q++){
				for(r=0;r<=m;r++){
					for(s=0;s<=m;s++){
						if(M[p][q][r][s]==1){
							op++;
							printf("%lld %lld %lld %lld\n",p,q,r,s);
						}
					}
				}
			}
		}
		printf("%lld\n",op);
		//printf("options:%lld  m:%lld  ",op,m);cha=op-last;
	//	printf("cha:%lld\n",cha);last=op;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
