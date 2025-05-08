#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=998244353;
int Q,a,x,i,ans;
int kuai(int y,int k){
	int r=1;
	if(k==0)return 1;
	else{
		while(k>1){
			if(k%2==0){
				k/=2;
				y=y*y;
				y%=inf;
			}
			else{
				k--;
				r*=y;
				r%=inf;
			}
		}
		int anss=(y*r)%inf;
		return anss;
	}
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>Q;
	for(int o=1;o<=Q;o++){
		scanf("%lld%lld",&a,&x);
		if(x==1){
			ans=a%inf;
			printf("%lld\n",ans);
		}
		else if(x==2){
			ans=a*a%inf;
			printf("%lld\n",ans);
		}
		else{
			ans=a*a%inf;
			int anss=x*(x-1)/2;
			anss%=inf;
			ans=ans*anss;
			ans%=inf;
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
