#include<bits/stdc++.h>
#define int long long
#define lc(x) tree[x].ch[0]
#define rc(x) tree[x].ch[1]
#define vc(x) tree[x].val
using namespace std;
struct nod{
	int ch[2],val;
};
int n,i,a[10000009],cnt;
int read(){
	int a=0;
	char c=getchar();
	while(c!='\n'&&c!=-1&&c!=' '){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n;getchar();
	for(i=1;i<=n;i++)a[i]=read();
	
	fclose(stdin);fclose(stdout);
	return 0;
}
