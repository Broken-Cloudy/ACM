#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,n,zao=999999LL,len,j,k,ans;
bool FF=0;
string s[109];
string cc="chi1 huo3 guo1";
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	while(s[i]!="."){
		i++;
		getline(cin,s[i]);
	}
	i--;n=i;
	for(i=1;i<=n;i++){
		len=s[i].length();
		for(j=0;j<len;j++){
			if(j>=13){
				FF=0;
				for(k=0;k<=13;k++){
					if(cc[k]!=s[i][j-13+k]){
						FF=1;
						break;
					}
				}
				if(FF==0){
					zao=min(zao,i);
					ans++;
					break;
				}
			}
		}
	}
	printf("%lld\n",n);
	if(ans>0)printf("%lld %lld",zao,ans);
	else printf("-_-#");
	fclose(stdin);fclose(stdout);
	return 0;
}
