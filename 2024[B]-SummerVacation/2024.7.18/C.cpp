#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,ans,cur,f[1000009][4];
char a[1000009][4];
signed main(){
	freopen("C.in","r",stdin);freopen("C.out","w",stdout);
	cin>>n;
	a[0][1]=a[0][2]='W';
	getchar();
	for(i=1;i<=n;i++){
		a[i][1]=getchar();
	}
	getchar();
	for(i=1;i<=n;i++){
		a[i][2]=getchar();
	}
	for(i=1;i<=n;i++){
		if(a[i][1]=='R'){
			f[i][1]=f[i-1][1]+1;
		}
		else a[i][1]=0;
		if(a[i][2]=='R'){
			f[i][2]=f[i-1][2]+1;
		}
		else a[i][2]=0;
		if(a[i][2]=='R'&&a[i][1]=='R'){
			if(f[i][2]>f[i][1]){
				f[i][1]=f[i][2]+1;
			}
			else if(f[i][2]<f[i][1])f[i][2]=f[i][1]+1;
			else{
				f[i][2]++;
				f[i][1]++;
			}
		}
	}
	for(i=1;i<=n;i++){
		ans=max(ans,max(f[i][1],f[i][2]));
	}
	cout<<max(0LL,ans-1)<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
