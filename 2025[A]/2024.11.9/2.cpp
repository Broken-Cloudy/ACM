#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,C1,C0,kk,c1,c0;
char s[100009],r[100009];
bool ff,fff;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);fff=0;
		getchar();for(i=1;i<=n;i++)s[i]=getchar();
		getchar();for(i=1;i<=n-1;i++)r[i]=getchar();
		c0=C0=0;ff=0;
		for(i=1;i<=n;i++){//c0
			if(ff==0){
				if(s[i]=='1'){
					c0++;
				}
				else{
					ff=1;
					C0+=c0;
				}
			}
			else{
				if(s[i]=='1'){
					C0++;
				}
			}
		}
		c1=C1=0;ff=0;
		for(i=1;i<=n;i++){//c0
			if(ff==0){
				if(s[i]=='0'){
					c1++;
				}
				else{
					ff=1;
					C1+=c1;
				}
			}
			else{
				if(s[i]=='0'){
					C1++;
				}
			}
		}
		for(i=1;i<=n-1;i++){
			if(r[i]=='1')C1--;
			else C0--;
			if(i==n-1&&C1>=0&&C0>=0)break;
			if(C1==0||C0==0){
				fff=1;
				break;
			}
		}
		if(fff==1)printf("NO\n");
		else printf("YES\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
