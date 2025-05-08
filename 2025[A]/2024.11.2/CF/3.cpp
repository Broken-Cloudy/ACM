#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,k,j,r[200009],ans,len,q,v,ff;
char c[200009],u;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%s",c+1);ff=0;
		len=strlen(c+1);
		for(i=1;i<=len-3;i++){
			if(c[i]=='1'&&c[i+1]=='1'&&c[i+2]=='0'&&c[i+3]=='0'){
				ff++;
			}
		}
		scanf("%lld",&q);
		while(q--){
			scanf("%lld%lld",&i,&v);
			for(j=max(1LL,i-3);j<=min(i,len-3);j++){
				if(c[j]=='1'&&c[j+1]=='1'&&c[j+2]=='0'&&c[j+3]=='0'){
					ff--;
				}
			}
			u=v+48;
			c[i]=u;
			for(j=max(1LL,i-3);j<=min(i,len-3);j++){
				if(c[j]=='1'&&c[j+1]=='1'&&c[j+2]=='0'&&c[j+3]=='0'){
					ff++;
				}
			}
			if(ff==0)printf("NO\n");
			else printf("YES\n");
		}
		for(i=1;i<=len;i++)c[i]=0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
