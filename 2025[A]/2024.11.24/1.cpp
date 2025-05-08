#include<bits/stdc++.h>
#define int long long
using namespace std;
const int AA=2e5+9;
int a[AA],cnt[AA],i,j,n,sum[AA],ans,SUM,kk;
map<int,map<int,int>>M;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
		if(a[i]>0){
			cnt[i]=cnt[i-1]+1;
		}
		else cnt[i]=cnt[i-1];
	}
	if(a[1]>0)M[a[1]][0]=1,M[a[1]][1]=1;
	for(i=2;i<=n-1;i++){
		if(sum[i]%2==0&&cnt[n]-cnt[i]>0){
			kk=sum[i]/2;
			if(sum[n]-sum[i]==kk){
				for(j=M[kk][0];j>=1;j--){
					if(cnt[i]-cnt[M[kk][j]]>0){
						ans+=j;
						break;
					}
				}
			}
		}
		if(cnt[i]>0){
			M[sum[i]][0]++;
			M[sum[i]][M[sum[i]][0]]=i;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
