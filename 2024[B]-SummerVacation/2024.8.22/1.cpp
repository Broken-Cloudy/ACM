#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,x,n,ans,k,r1,r2,i,j,k1,k2,t1,t2;
map<int,int>m;
int check(int x,int y){
	if(m[y]==1)return 0;
	if(y%2==0){
		if(x%y==0){
			m[y]=1;
			return 1;
		}
		else return 0;
	}
	else return 0;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&x);
		r1=n-x;r2=n+x-2;ans=0;m.clear();
		for(i=1;i*i<=r1;i++){
			if(r1%i==0){
				k1=i;k2=r1/i;
				t1=(k1+2)/2;
				t2=(k2+2)/2;
				if(t1>=x)ans+=check(r1,k1);
				if(t2>=x)ans+=check(r1,k2);
			}
		}
		for(i=1;i*i<=r2;i++){
			if(r2%i==0){
				k1=i;k2=r2/i;
				t1=(k1+2)/2;
				t2=(k2+2)/2;
				if(t1>=x)ans+=check(r2,k1);
				if(t2>=x)ans+=check(r2,k2);
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
