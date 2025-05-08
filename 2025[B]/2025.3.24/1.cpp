#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,n,k,a[10009],b[10009],ton[1000009],ans,maxx,K,x,y,now;
int d[100009];
map<int,int>M;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);maxx=0;ans=-1;
		d[0]=0;M.clear();
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++)scanf("%lld",&b[i]),ton[b[i]]++,maxx=max(maxx,b[i]);
		sort(a+1,a+1+n);sort(b+1,b+1+n);
		for(i=1;i<=n;i++){//a[n]ÕÒb  10000
			K=a[n]-b[i];
			for(j=1;j*j<=K;j++){
				if(K%j==0){
					x=j;y=K/j;
					if(x>maxx){
						if(M[x]==0){
							M[x]=1;
							d[++d[0]]=x;
						}
					}
					if(y>maxx){
						if(M[y]==0){
							M[y]=1;
							d[++d[0]]=y;
						}
					}
				}
			}
		}
		now=1;sort(d+1,d+1+d[0]);
		while(now<=d[0]){//10^8 ?
			k=d[now];now++;
			for(i=n;i>=1;i--){
				ton[a[i]%k]--;
				if(ton[a[i]%k]<0)break;
			}
			if(i==0){
				ans=k;
				break;
			}
			else{
				for(j=n;j>=i;j--){
					ton[a[j]%k]++;
				}
			}
		}
		if(ans==-1){
			k=12345678;
			for(i=n;i>=1;i--){
				ton[a[i]%k]--;
				if(ton[a[i]%k]<0)break;
			}
			if(i==0){
				ans=k;
			}
			else{
				for(j=n;j>=i;j--){
					ton[a[j]%k]++;
				}
			}
		}
		printf("%lld\n",ans);
		for(i=1;i<=n;i++)ton[b[i]]=0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
