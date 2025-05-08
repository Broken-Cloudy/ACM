#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200009];
int n,m,k,i,ans,f[200009][6][2];
char c[200009];
bool check(int x,int ci,int k){
	int i,j;
	int ANS=1000000009;
	for(i=0;i<=n;i++){
		for(j=1;j<=k;j++){
			f[i][j][0]=f[i][j][1]=1000000009;
		}
	}
	for(i=1;i<=n;i++){
		for(j=k;j>=1;j--){
			if(i>=x){
				if(c[i-x]=='0'){
					f[i][j][1]=f[i-x][j-1][0]+(a[i]-a[i-x]);
				}
				f[i][j][0]=min(f[i-1][j][0],f[i-1][j][1]);
			}
		}
	}
	for(i=1;i<=n;i++)ANS=min(ANS,f[i][k][0]),ANS=min(ANS,f[i][k][1]);
	if(ANS>ci)return 0;
	else return 1;
}
void work(int l,int r,int ci,int k){
	int mid=(l+r)/2;
	if(l==r){
		if(check(l,m,k)){
			ans=l;
			return;
		}
		else{
			ans=-1;
			return;
		}
	}
	else if(l+1==r){
		if(check(r,m,k)){
			ans=r;
			return;
		}
		else if(check(l,m,k)){
			ans=l;
			return;
		}
		else{
			ans=-1;
			return;
		}
	}
	if(check(mid,m,k)==1){
		work(mid,r,m,k);
	}
	else{
		work(l,mid,m,k);
	}
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n>>m>>k;getchar();
	c[0]='0';
	for(i=1;i<=n;i++){
		c[i]=getchar();
		if(c[i]=='0'){
			a[i]=a[i-1]+1;
		}
		else a[i]=a[i-1];
	}
	work(1,n,m,k);
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
