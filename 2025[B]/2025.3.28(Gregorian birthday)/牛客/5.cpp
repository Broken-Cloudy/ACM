#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[2009],i,j,GCD,k[2009],f[2009][2009],kk,d,vis[2009];
bool FF=1;
void gcd(int a,int b){
	if(b==0){
		GCD=a;
		return;
	}
	else gcd(b,a%b);
}
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	k[++k[0]]=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			gcd(a[i],a[j]);
			if(GCD>1)f[i][j]=1;
		}
	}
	for(i=1;i<=n;i++){
		if(vis[i]==1){
			for(j=i-1;j>=1;j--){
				if(f[i][j]==1){
					kk=j;
					break;
				}
			}
			while(k[k[0]]>kk){
				k[0]--;
			}
			k[++k[0]]=i+1;
			continue;
		}
		kk=-1;
		for(j=i+1;j<=n;j++){
			if(f[i][j]==1){
				kk=j;
				break;
			}
		}
		if(kk==-1){
			for(j=i-1;j>=1;j--){
				if(f[i][j]==1){
					kk=j;
					break;
				}
			}
		}
		else{
			vis[kk]=1;
			while(k[k[0]]>i){
				k[0]--;
			}
			k[++k[0]]=kk+1;
			continue;
		}
		if(kk==-1){
			FF=0;
			break;
		}
		else{
			while(k[k[0]]>kk){
				k[0]--;
			}
			k[++k[0]]=i+1;
		}
	}
	if(FF==0)printf("-1\n");
	else printf("%lld\n",k[0]-1);
	fclose(stdin);fclose(stdout);
	return 0;
}
