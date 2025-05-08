#include<bits/stdc++.h>
#define int long long
using namespace std;
char c[1009];
int len,i,j,k,nowans,ans;
signed main(){
	freopen("L2-4.in","r",stdin);freopen("L2-4.out","w",stdout);
	cin.getline(c+1,1005);
	len=strlen(c+1);
	for(i=1;i<=len;i++){
		nowans=0;
		for(j=i,k=i-1;k>=1&&j<=len;k--,j++){
			if(c[j]==c[k]){
				nowans+=2;
			}
			else break;
		}
		ans=max(nowans,ans);
		nowans=0;
		for(j=i+1,k=i;k>=1&&j<=len;k--,j++){
			if(c[j]==c[k]){
				nowans+=2;
			}
			else break;
		}
		ans=max(nowans,ans);
		nowans=1;
		for(j=i+1,k=i-1;k>=1&&j<=len;k--,j++){
			if(c[j]==c[k]){
				nowans+=2;
			}
			else break;
		}
		ans=max(nowans,ans);
	}
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
