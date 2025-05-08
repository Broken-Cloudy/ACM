#include<iostream>
#define int long long
using namespace std;
int T,a[200009],n,i,j,k,w,d,gcd,ans,GCD;
bool ff;
void gg(int x,int y){
	if(y==0){
		GCD=x;
		return;
	}
	else gg(y,x%y);
}
int check(int x,int y){
	int z=min(x,y);
	y=max(x,y);x=z;
	if(y%x==0)return x;
	else{
		gg(x,y);
		if(x%GCD==0&&y%GCD==0&&GCD!=1)return GCD;
		else return -1;
	}
}
int abss(int x){return max(x,-x);}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);ans=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(w=1;w*w<=n;w++){
			if(n%w==0){
				k=w;
				ff=0;gcd=0;
				for(i=1;i<=k;i++){
					if(ff==1)break;
					for(j=i+k;j<=n;j+=k){
						d=abss(a[j]-a[j-k]);
						if(d==0)continue;
						else if(d==1){
							ff=1;break;
						}
						if(gcd==0)gcd=d;
						else{
							if(check(gcd,d)==-1){
								ff=1;break;
							}
							else gcd=check(gcd,d);
						}
					}
				}
				if(ff==0)ans++;
				if(w*w==n)continue;
				k=n/w;
				ff=0;gcd=0;
				for(i=1;i<=k;i++){
					if(ff==1)break;
					for(j=i+k;j<=n;j+=k){
						d=abss(a[j]-a[j-k]);
						if(d==0)continue;
						else if(d==1){
							ff=1;break;
						}
						if(gcd==0)gcd=d;
						else{
							if(check(gcd,d)==-1){
								ff=1;break;
							}
							else gcd=check(gcd,d);
						}
					}
				}
				if(ff==0)ans++;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
