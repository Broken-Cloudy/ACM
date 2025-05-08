#include<bits/stdc++.h>
using namespace std;
int i,n,f[100009][139],K,ans,k,ANS,a[100009];
int main(){
	freopen("K.in","r",stdin);freopen("K.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		f[i][k]=i+1;
	}
	for(K=2;K<=139;K++){
		for(i=1;i<=n;i++){
			if(f[i][K]==0){
				if(f[f[i][K-1]][K-1]!=0)a[i]=a[f[f[i][K-1]][K-1]]+1;
				f[i][K]=f[f[i][K-1]][K-1];
			}
			if(f[i][K]!=0){
				if(K>ans){
					ans=K;
					ANS=a[f[i][K]+1];
				}
				else if(K==ans){
					ANS=min(ANS,a[f[i][K]+1]);
				}
			}
		}
	}
	cout<<ans<<' '<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
