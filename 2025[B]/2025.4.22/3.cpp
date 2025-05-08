#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,w[500009],c[500009],i,j,p[500009][24],f[500009],maxx,ANS=1,g[500009];
int F[500009];
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n;
	for(i=2;i<=500000;i++){
		if(p[i][0]==0){
			for(j=i;j<=500000;j+=i){
				p[j][++p[j][0]]=i;
			}
		}
	}
	for(i=1;i<=n;i++)scanf("%lld",&w[i]);
	for(i=1;i<=n;i++)scanf("%lld",&c[i]);
	for(i=1;i<=n;i++){
		maxx=0;
		for(j=1;j<=p[w[i]][0];j++){
			if(g[p[w[i]][j]]==c[i])maxx=max(maxx,F[p[w[i]][j]]+1);
			else maxx=max(maxx,f[p[w[i]][j]]+1);
		}
		for(j=1;j<=p[w[i]][0];j++){
			if(g[p[w[i]][j]]!=c[i]){
				g[p[w[i]][j]]=c[i];
				F[p[w[i]][j]]=f[p[w[i]][j]];//不选择当前数字 
				f[p[w[i]][j]]=max(maxx,f[p[w[i]][j]]);//选择当前数字 
			}
			else{
				f[p[w[i]][j]]=max(maxx,f[p[w[i]][j]]);//不选择当前数字 
			}
		}
	}
	for(i=1;i<=500000;i++){
		ANS=max(ANS,f[i]);
	}
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
/*
8
2 2 2 2 2 210 77 11
1 2 3 4 5 6 6 7
*/
