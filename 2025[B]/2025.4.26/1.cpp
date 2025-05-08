#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,j,f[12];
string s;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>s;
		memset(f,0,sizeof(f));
		for(i=0;i<=9;i++){
			f[(s[i]-'0')]++;
		}
		for(i=9;i>=0;i--){
			for(j=i;j<=9;j++){
				if(f[j]>0){
					printf("%lld",j);
					f[j]--;
					break;
				}
			}
		}
		printf("\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
