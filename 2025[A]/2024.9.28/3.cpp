#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[3009],i,j,ans;
int f[3009][3009],deta[3009][3009];
int dfs(int bh,int l,int r,int D){
	if(l==r){
		if(deta[bh][l]==D)return l;
		else return -1;
	}
	else if(l+1==r){
		if(deta[bh][l]==D)return l;
		else if(deta[bh][r]==D)return r;
		else return -1;
	}
	else{
		int mid=(l+r)/2;
		if(deta[bh][mid]>D){
			return dfs(bh,l,mid,D);
		}
		else return dfs(bh,mid,r,D);
	}
}
int check(int bh,int D){
	int l=1,r=f[bh][0],anss;
	anss=dfs(bh,l,r,D);
	if(anss==-1)return 0;
	else return anss;
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=1;i<=n;i++){
		for(j=i-1;j>=1;j--){
			int d=a[i]-a[j];
			if(check(j,d)){
				f[i][0]++;
				f[i][f[i][0]]=f[j][check(j,d)]+1;
				deta[i][f[i][0]]=d;
			}
			else{
				f[i][0]++;
				f[i][f[i][0]]++;
				deta[i][f[i][0]]=d;
			}
			ans=max(f[i][f[i][0]],ans);
		}
	}
	cout<<ans+1<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
