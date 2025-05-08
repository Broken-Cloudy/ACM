#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,r,kk,f[36];
bool FF;
char c[100009],p[12];
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	p[1]='C';p[2]='H';p[3]='I';p[4]='C';p[5]='K';p[6]='E';p[7]='N';	
	cin>>T;
	while(T--){
		scanf("%lld",&n);getchar();r=1;FF=1;
		for(i=1;i<=n;i++)c[i]=getchar();
		for(i=1;i<=30;i++)f[i]=0;
		for(i=1;i<=n;i++){
			if(r>7){
				f[c[i]-'A'+1]++;
			}
			else{
				if(p[r]==c[i])r++;
				else{
					f[c[i]-'A'+1]++;
				}
			}
		}
		kk=0;
		for(i=1;i<=30;i++){
			kk+=f[i];
		}
		for(i=1;i<=30;i++){
			if(f[i]>kk/2)FF=0;
		}
		if(r<=7)FF=0;
		if(kk%2==1)FF=0;
		if(FF==1)printf("YES\n");
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
