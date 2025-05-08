#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,T,ans,i,j,b,f[200009];//f[]ÌåÁ¦Öµ 
const int inf=1e9+7;
char a[200009];
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;a[0]='L';
	for(int o=1;o<=T;o++){
		scanf("%lld%lld%lld",&n,&m,&k);getchar();
		a[n+1]='L';
		for(i=1;i<=n;i++){
			a[i]=getchar();
		}
		for(i=1;i<=n+1;i++)f[i]=-1000000;
		f[0]=k;
		for(i=0;i<=n+1;i++){
			if(f[i]==inf)continue;
			if(a[i]=='W'){
				f[i]=max(f[i],f[i-1]-1);
			}
			else if(a[i]=='L'){
				f[i]=max(f[i],f[i-1]-1);
				for(j=i+1;j<=i+m;j++){
					if(a[j]!='C')f[j]=f[i];
				}
			}
			else{
				f[i]=-1000000;
			}
		}
		if(f[n+1]<0){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
