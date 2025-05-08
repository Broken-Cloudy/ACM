#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1009],i,f[1009],j,p[1009][1009],k;
queue<int>q;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=1;i<=n;i++){
		for(j=1;j<=1000;j++){
			if(a[i]%j==0)p[i][++p[i][0]]=j;
		}
	}
	for(i=1;i<=n;i++)f[i]=1e18+9;
	q.push(1);f[1]=0;
	while(!q.empty()){
		i=q.front();q.pop();
		if(i==n){
			break;
		}
		for(k=1;k<=p[i][0];k++){
			j=p[i][k];
			if(a[i]%j!=0)continue;
			if(i+j>n&&i-j<1)break;
			else{
				if(i+j<=n){
					if(f[i]+1<f[i+j]){
						q.push(i+j);
						f[i+j]=f[i]+1;
					}
				}
				if(i-j>=1){
					if(f[i]+1<f[i-j]){
						q.push(i-j);
						f[i-j]=f[i]+1;
					}
				}
			}
		}
	}
	cout<<f[n]<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
