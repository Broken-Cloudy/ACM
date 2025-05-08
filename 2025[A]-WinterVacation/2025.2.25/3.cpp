#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,j,k,t,a[100009],T,ANS,f[100009],ans[200009],kk;
queue<int>q;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ANS=n*(n+1)/2;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(k=1;k<=10;k++){
			for(i=1;i<=n;i++){
				if(a[i]>k)f[i]=1;
				else f[i]=-1;
			}
			while(!q.empty())q.pop();
			kk=n;for(i=0;i<=2*n;i++)ans[i]=0;
			for(i=1;i<=n;i++){
				q.push(kk);
				if(a[i]==k){
					while(!q.empty()){
						t=q.front();q.pop();
						ans[t]++;
					}
				}
				if(f[i]==1)kk--;
				else kk++;
				ANS-=ans[kk];
			}
		}
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
