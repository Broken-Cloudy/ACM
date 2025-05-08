#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,cnt,c0,c1,i;
char c[200009],ch;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld",&n);getchar();
		cnt=0;c0=c1=0;
		for(i=1;i<=n;i++){
			ch=getchar();
			if(c[cnt]=='0'&&ch=='0')continue;
			else c[++cnt]=ch;
		}
		for(i=1;i<=cnt;i++){
			if(c[i]=='0')c0++;
			else c1++;
		}
		if(c1>c0)printf("YES\n");
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
