#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n,i,a[100009],b[100009],l,r,c,ans;
/*int check(int x){
	int i,ans=0;
	for(i=1;i<=n;i++){
		ans+=(x-b[i])/a[i];
	}
}*/
void dfs(int L,int R){
	if(L==R){
		ans=L;
		return;
	}
	int mid=(L+R)/2;
	int i,ci=0;
	for(i=1;i<=n;i++){
		if(mid>=b[i]){
			if(l>=b[i]){
				int x,y;
				x=(mid-b[i])/a[i]+1;
				if((l-b[i])%a[i]==0)y=(l-b[i])/a[i];
				else y=(l-b[i])/a[i]+1;
				ci+=(x-y);
			}
			else{
				int x;
				x=(mid-b[i])/a[i]+1;
				ci+=x;
			}
		}
	}
	if(ci>=c){
		dfs(L,mid);
	}
	else{
		dfs(mid+1,R);
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%lld",&b[i]);
	}
	cin>>l>>r>>c;
	int Ci=0;
	for(i=1;i<=n;i++){
		if(r>=b[i]){
			if(l>=b[i]){
				int x,y;
				x=(r-b[i])/a[i]+1;
				if((l-b[i])%a[i]==0)y=(l-b[i])/a[i];
				else y=(l-b[i])/a[i]+1;
				Ci+=(x-y);
			}
			else{
				int x;
				x=(r-b[i])/a[i]+1;
				Ci+=x;
			}
		}
	}
	if(Ci<c){
		cout<<-1<<endl;
	}
	else{
		dfs(l,r);
		cout<<ans<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
