#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,L,R,a[3200009],X,p1[3200009],ans,t;
bool F;
int dfs(int x){
	if(x>8LL*n){
		if(F==1){
			if(dfs(x/2)==1){
				if(x%2==1){
					return 0;
				}
				else return 1;
			}
			else{
				return 0;
			}
		}
		else{
			if(dfs(x/2)==1){
				if(x%2==1){
					return 1;
				}
				else return 0;
			}
			else{
				return 1;
			}
		}
	}
	else{
		if(F==1){
			if(a[x]==1){
				if(x%2==1){
					return 0;
				}
				else return 1;
			}
			else{
				return 0;
			}
		}
		else{
			if(a[x]==1){
				if(x%2==1){
					return 1;
				}
				else return 0;
			}
			else{
				return 1;
			}
		}
	}
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&L,&R);X=L;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(a[i]==0)p1[i]=p1[i-1];
			else p1[i]=p1[i-1]+1;
		}
		for(i=n+1;i<=8*n;i++){
			t=i/2;
			if(p1[t]%2==1){
				a[i]=1;
				p1[i]=p1[i-1]+1;
			}
			else{
				a[i]=0;
				p1[i]=p1[i-1];
			}
		}
		if(n%2==0)i=n+2;
		else i=n+1;
		t=i*2;
		if(a[i]==1){
			if(a[t]==1&&a[t+1]==1)F=1;
			else F=0;
		}
		else{
			if(a[t]==0&&a[t+1]==0)F=1;
			else F=0;
		}
		if(X>8LL*n)ans=dfs(X/2);
		else ans=a[X];
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
