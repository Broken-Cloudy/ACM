#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=998244353;
int f[10000009],i,a[10000009],j,n,S,SS;
int MM,x,y;
void exgcd(int a,int b){
	if(b==0){
		x=1;y=0;
		return;
	}
	exgcd(b,a%b);
	int t=x;
	x=y;
	y=t-(a/b)*y;
}
signed main(){
//	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0<<endl;
		fclose(stdin);fclose(stdout);
		return 0;
	}
	else if(n==2){
		cout<<1<<endl;
		fclose(stdin);fclose(stdout);
		return 0;
	}
	else{
		for(i=1;i<=10000000;i++)a[i]=i;
		for(i=1;i<=10000000;i++){
			if(a[i]==1)continue;
			else{
				for(j=i*2;j<=10000000;j+=i){
					if(a[j]%a[i]==0){
						a[j]/=a[i];	
					}
				}
			}
		}
		f[2]=1;MM=2;S=1;
		for(i=3;i<=n;i++){
			MM=MM*a[i]%inf;
			S*=a[i];S%=inf;
			exgcd(i,inf);
			S=(S+MM*(x+inf)%inf)%inf;
			f[i]=f[i-1]*a[i]%inf+S%inf;
		}
	}
	cout<<f[n]%inf<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
