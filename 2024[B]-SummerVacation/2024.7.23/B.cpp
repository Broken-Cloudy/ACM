#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,D,cnt,h[109],i,g;
void G(int a,int b){
	if(b==0){
		g=a;
		return;
	}
	else{
		G(b,a%b);
	}
}
signed main(){
	freopen("B.in","r",stdin);freopen("B.out","w",stdout);
	cin>>n>>D;
	for(i=1;i<=n;i++)scanf("%lld",&h[i]);
	for(i=1;i<=n;i++){
		G(g,h[i]);
	}
	cout<<D%g<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
} 
