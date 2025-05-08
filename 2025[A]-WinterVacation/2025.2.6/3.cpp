#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,ANS;
char c[19],b[19];
int check(){
	int i;
	int n01=0,n10=0;
	for(i=2;i<=n;i++){
		if(b[i-1]=='0'&&b[i]=='1')n01++;
		else if(b[i-1]=='1'&&b[i]=='0')n10++;
	}
	if(n01==n10)return 1;
	else return 0;
}
void dfs(int x){
	int i;
	if(x==n+1){
		for(i=1;i<=n;i++){
			b[i]=(b[i]=='1'?'0':'1');
			ANS+=check();
			b[i]=(b[i]=='1'?'0':'1');
		}
		
		return;
	}
	if(c[x]=='?'){
		b[x]='1';
		dfs(x+1);
		b[x]='0';
		dfs(x+1);
	}
	else{
		b[x]=c[x];
		dfs(x+1);
	}
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);getchar();ANS=0;
		for(i=1;i<=n;i++)c[i]=getchar();
		dfs(1);
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
