#include<bits/stdc++.h>
using namespace std;
const long long inf=30000005;
char s[120];
long long len,i,n,q,has,j,h[120],cnt;
bool a[30000009],b[30000009];
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++){
		has=0;
		scanf("%s",s+1);
		len=strlen(s+1);
		for(j=1;j<=len;j++){
			if(s[j]>='a'&&s[j]<='z'){
				has=has*54+(s[j]-'a')*54;
			}
			else{
				has=has*54+(s[j]-'A'+26)*54;
			}
			has%=inf;
		}
		a[has]=1;
		has=0;
		for(j=1;j<=len;j++){
			if(s[j]>='a'&&s[j]<='z'){
				has=has*57+(s[j]-'a')*57;
			}
			else{
				has=has*57+(s[j]-'A'+26)*57;
			}
			has%=inf;
		}
		b[has]=1;
	}
	for(i=1;i<=q;i++){
		has=0;
		scanf("%s",s+1);
		len=strlen(s+1);
		for(j=1;j<=len;j++){
			if(s[j]>='a'&&s[j]<='z'){
				has=has*54+(s[j]-'a')*54;
			}
			else{
				has=has*54+(s[j]-'A'+26)*54;
			}
			has%=inf;
		}
		int hs=0;
		for(j=1;j<=len;j++){
			if(s[j]>='a'&&s[j]<='z'){
				hs=hs*57+(s[j]-'a')*57;
			}
			else{
				hs=hs*57+(s[j]-'A'+26)*57;
			}
			hs%=inf;
		}
		if(a[has]==1&&b[hs]==1)printf("YES\n");
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
