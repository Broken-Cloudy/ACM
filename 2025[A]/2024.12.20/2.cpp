#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i;
int FF,ss,pp,p,s;
char c[509];
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		FF=ss=pp=s=p=0;
		scanf("%lld",&n);getchar();
		for(i=1;i<=n;i++)c[i]=getchar();
		for(i=1;i<=n;i++){
			if(i!=1&&i!=n){
				if(c[i]=='s'){
					ss=1;
				}
				if(c[i]=='p'){
					pp=1;
				}
			}
			if(c[i]=='s'){
				s=1;
				if(p==1)FF=1;
			}
			if(c[i]=='p')p=1;
		}
		if(ss==1&&pp==1||FF==1)printf("NO\n");
		else printf("YES\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
