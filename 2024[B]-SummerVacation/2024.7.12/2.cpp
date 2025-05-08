#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100009],b[1000009],i,j,k,ans,w,vis[1000009];
int clear[1000009],cnt;
int c[13];
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=n;i>=1;i--){
		for(j=1;j*j<=a[i];j++){
			if(a[i]%j==0){
				k=a[i]/j;
				c[1]=1;c[2]=j;c[3]=k;c[4]=j*j;c[5]=j*k;c[6]=k*k;
				c[7]=j*k*k;c[8]=k*j*j;c[9]=j*j*k*k;
				for(w=1;w<=9;w++){
					if(c[w]<=1000000){
						if(vis[c[w]]==0){
							ans+=b[c[w]];
							vis[c[w]]=1;
							clear[++cnt]=c[w];
						}
					}
				}
			}
		}
		b[a[i]]++;
		for(j=1;j<=cnt;j++){
			vis[clear[j]]=0;
		}
		cnt=0;
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
