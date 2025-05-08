#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,i,j,m,r,l,ans,R,D,rr,dd,bh[109];
char c[100009];
signed main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	if(n<=10){
		cin>>n;getchar();
	for(i=1;i<=n;i++){
		c[i]=getchar();
		if(c[i]=='0')bh[++bh[0]]=i;
	}
	cout<<bh[0]<<endl;
	for(i=1;i<=bh[0];i++)cout<<bh[i]<<' ';
	}
	else cout<<"-1"<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
