#include<bits/stdc++.h>
using namespace std;
long long n,p,i,cnt,j;
long long x,y,t,gcd;
long long ans[3000006];
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>p;ans[1]=1;
	cout<<ans[1]<<endl;
	for(i=2;i<=n;i++){
        ans[i]=(long long)(p-p/i)*ans[p%i]%p;
        printf("%lld\n",ans[i]);
    }
	fclose(stdout);fclose(stdout);
	return 0;
} 
