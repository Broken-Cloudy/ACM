#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=998244353ll;
int i,j,x,y,p,q,r,a[200009],n,ni=1000000ll,ans;
void exgcd(int a,int b){
	if(b==0){
		x=1;y=0;
		return;
	}
	exgcd(b,a%b);
	int t=x;
	x=y;y=t-(a/b)*y;
}
int to_left(int bh){
	int anss=0;
	anss=(r*1+(p+q)*q%inf)%inf;
	return anss;
}
int to_right(int bh){
	int anss=0;
	anss=(r*1+(p+q)*p%inf)%inf;
	return anss;
}
int to_er(int bh){
	int anss=0;
	anss=(r*1+(p+q)*(q+p-p*q%inf+inf)%inf+inf)%inf;
	return anss;
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>p>>q;r=ni-p-q;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	exgcd(ni,inf);ni=(x%inf+inf)%inf;
	p=(p*ni)%inf;r=(r*ni)%inf;q=(q*ni)%inf;
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++){
		if(i==1){
			if(n>=2&&a[2]==a[1]+1){
				ans=(ans+to_right(1))%inf;
			}
			else ans=(ans+r*1)%inf;
		}
		else if(i==n){
			if(n>=2&&a[n]==a[n-1]+1){
				ans=(ans+to_left(n))%inf;
			}
			else ans=(ans+r*1)%inf;
		}
		else{
			if(a[i]==a[i-1]+1&&a[i]==a[i+1]-1){
				ans=(ans+to_er(i))%inf;
			}
			else if(a[i]==a[i-1]+1){
				ans=(ans+to_left(i))%inf;
			}
			else if(a[i]==a[i+1]-1){
				ans=(ans+to_right(i))%inf;
			}
			else ans=(ans+r*1)%inf;
		}
	}
	cout<<ans%inf<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
