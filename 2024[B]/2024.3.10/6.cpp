#include<bits/stdc++.h>
using namespace std;
int n,f[1000009],san,i,j,ans,g[908];
bool ff;
int main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>n;
	for(i=1;i<=100000;i++){
		if(i%2==0)f[i]=1;
	}
	for(i=1;i<=1000;i++){
		san+=i;
		f[san]=1;
	}
	for(i=5;i<=100000;i++){
		ff=0;
		for(j=2;j*j<=i;j++){
			if(i%j==0){
				ff=1;
				break;
			}
		}
		if(ff==0){
			f[i]=1;
		}
	}
	g[0]=1;g[1]=1;i=2;
	while(g[i-1]<=100000){
		for(j=0;j<=i-1;j++){
			g[i]+=g[j]*g[i-j-1];
		}
		if(g[i]<=100000){
			f[g[i]]=1;
		}
		i++;
	}
	for(i=1;i<=n;i++){
		if(f[i]==0){
			ans++;
		}
	}
	printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
