#include<bits/stdc++.h>
using namespace std;
long long a[509],i,n,m,b,p,f[509][509],j,k,ans;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>m>>b>>p;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	f[0][0]=1;
	for(i=1;i<=n;i++){
		int cnt=0;
		while(a[i]*cnt<=b&&cnt<=m){
			for(j=b;j>=a[i]*cnt;j--){
				for(k=m;k>=cnt;k--){
					if(cnt==0)f[j][k]++;
					else f[j][k]+=f[j-a[i]*cnt][k-cnt];
				}
			}
			cnt++;
		}
	}
	for(i=0;i<=b;i++){
		ans+=f[i][m];
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
} 
