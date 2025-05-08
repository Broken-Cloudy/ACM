#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,b[200009],q,len,k[200009],checker[200009],p[30],check;
map<int,int>m;
bool f;
char a[200009];
void getin(){
	char c;
	c=getchar();
	while(c!=' '&&c!=-1&&c!='\n'){
		a[++len]=c;
		c=getchar();
	}
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++)scanf("%lld",&b[i]);
		memset(p,0,sizeof(p));check=0;m.clear();
		for(i=1;i<=n;i++){
			if(m[b[i]]==0){
				m[b[i]]=++check;
			}
			k[i]=m[b[i]];
		}
		scanf("%lld",&q);getchar();
		while(q--){
			f=0;len=0;getin();
			if(len!=n){
				printf("NO\n");
				continue;
			}
			memset(p,0,sizeof(p));check=0;
			for(i=1;i<=len;i++){
				if(p[a[i]-'a'+1]==0){
					p[a[i]-'a'+1]=++check;
				}
				checker[i]=p[a[i]-'a'+1];
			}
			for(i=1;i<=len;i++){
				if(checker[i]!=k[i]){
					f=1;break;
				}
			}
			if(f==1)printf("NO\n");
			else printf("YES\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
