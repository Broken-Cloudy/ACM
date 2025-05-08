#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,i,j,vis[5000009],a[2009][2009],b[4009],c[4009],L,R,l,r,maxx,ans[4009];
int prime[10009],cnt;//cnt是素数的个数，prime里面全部都是素数 
int flag[100009];//0是质数，>0不是质数 
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>m>>k;
	if(n==1&&m==1){
		printf("%lld\n",1LL);
		printf("%lld\n",1LL);
		printf("%lld %lld\n",1LL,1LL);
		fclose(stdin);fclose(stdout);
		return 0;
	}
	flag[1]=1;
	for(i=2;i<=100000;i++){
		if(flag[i]==0){
			prime[++cnt]=i;//记录下来 
		}
		for(j=1;j<=cnt&&i*prime[j]<=100000;j++){
			flag[prime[j]*i]=prime[j];//一下子筛到底(最小因数) 
			//当然，i肯定比prime[j]大，因为prime[j]是在i之前得出的
			if(i%prime[j]==0)break;
		}
	}
	L=1;R=n+m-2;c[++c[0]]=1;l=1;r=n+m-2;
	for(i=L;i<R;i++)c[++c[0]]=prime[i];
	while(true){
		if(R==L){
			b[r]=c[R];//最大 
			break;
		}
		else if(R==L+1){
			b[r]=c[R];//最大 
			b[l]=c[R-1];//次大 
			break;
		}
		else if(R==L+2){
			b[r-1]=c[L];//最小 
			b[r]=c[R];//最大 
			b[l]=c[R-1];//次大 
			break;
		}
		else if(R==L+3){
			b[r-1]=c[L];//最小 
			b[r]=c[R];//最大 
			b[l+1]=c[L+1];//次小 
			b[l]=c[R-1];//次大 
			break;
		}
		else{
			b[r-1]=c[L];//最小 
			b[r]=c[R];//最大 
			b[l+1]=c[L+1];//次小 
			b[l]=c[R-1];//次大 
			R-=2;L+=2;r-=2;l+=2;
		}
	}
	if(b[2]==1)ans[1]=b[1]*2;else ans[1]=b[1];
	ans[n+m-1]=b[n+m-2]*2;maxx=max(ans[1],ans[n+m-1]);
	vis[ans[1]]=1;vis[ans[n+m-1]]=1;
	for(i=2;i<n+m-1;i++){
		ans[i]=b[i-1]*b[i];
		if(ans[i]<=5000000LL)vis[ans[i]]=1;
		maxx=max(maxx,ans[i]);
	}
	vis[0]=1;
	for(i=1;i<=n;i++)a[i][1]=ans[i];
	for(i=2;i<=m;i++)a[n][i]=ans[i-1+n];
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i][j]==0){
				while(vis[vis[0]]==1)vis[0]++;
				a[i][j]=vis[0];vis[vis[0]]=1;
			}
		}
	}
	maxx=max(maxx,vis[0]);
	if(maxx>k)printf("-1\n");
	else{
		printf("%lld\n",maxx);
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(j==m)printf("%lld\n",a[i][j]);
				else printf("%lld ",a[i][j]);
			}
		}
		for(i=1;i<=n;i++)printf("%lld %lld\n",i,1LL);
		for(i=2;i<=m;i++)printf("%lld %lld\n",n,i);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
