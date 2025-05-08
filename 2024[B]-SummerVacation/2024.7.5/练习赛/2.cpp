#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e9+7;
int n,k,i,w,d,a[1000009],p[1000009],ANS=1;
int fast(int x,int y){
    int ans=1;
    while(y>0){
        if(y%2==1){
            ans=(ans%inf*x%inf)%inf;
        }
        x=(x%inf*x%inf)%inf;
        y/=2;
    }
    return ans%inf;
}
int x,y;
void exgcd(long long a,long long b){
	if(b==0){
		x=1;y=0;
		return;
	}
	exgcd(b,a%b);
	int t=x;
	x=y;y=t-(a/b)*y;
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>w>>d;
	if(d==0){
		for(i=1;i<=w;i++){
			scanf("%lld%lld",&p[i],&a[i]);
			ANS=(ANS%inf)*(a[i]+1)%inf;
		}
	}
	else{
		for(i=1;i<=w;i++){
			scanf("%lld%lld",&p[i],&a[i]);
			int zhi1=fast(p[i],(d*(a[i]+1)))-1;
			if(zhi1<0)zhi1+=inf;
			ANS=(ANS%inf)*zhi1%inf;
			ANS%=inf;
			int zhi2=fast(p[i],d)-1;
			if(zhi2<0)zhi2+=inf;
			exgcd(zhi2,inf);
			ANS=((ANS%inf+inf)%inf*(x%inf+inf)%inf+inf)%inf;
		}
	}
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
