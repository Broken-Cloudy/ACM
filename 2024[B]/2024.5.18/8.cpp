#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,W,a[200009],i,SUM,f[200009],ANS;
bool check(int x){
	int i,ans=0;
	for(i=1;i<=n;i++)f[i]=0;
	for(i=1;i<=n;i++){
		if((i-x)<0||(i+x)>n+1)continue;
		else{
			f[i]=f[i-x]+a[i];
			f[i]=max(f[i],ans);
			ans=max(ans,f[i]);
		}
	}
	if(ans>=W)return 1;
	else return 0;
}
void dfs(int l,int r){
	if(l==r-1){
		if(check(r)){
			ANS=r;
			return;
		}
		else{
			ANS=l;
			return;
		}
	}
	else{
		int mid=(l+r)/2;
		if(check(mid)){
			dfs(mid,r);
		}
		else{
			dfs(l,mid);
		}
	}
}
signed main(){
	freopen("8.in","r",stdin);freopen("8.out","w",stdout);
	cin>>n>>W;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]),SUM+=a[i];
	if(SUM<W)printf("-1\n");
	else if(W==0)printf("%lld\n",n+1);
	else{
		dfs(1,n);
		cout<<ANS<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
