#include<bits/stdc++.h>
#define int long long
using namespace std;
int N,M,k,i,j,cnt;
double a[12],ans[10009],sum,ren;
signed main(){
	freopen("119.in","r",stdin);freopen("119.out","w",stdout);
	cin>>N>>k>>M;ren=k-2;
	for(i=1;i<=N;i++){
		sum=0;
		for(j=1;j<=k;j++){
			scanf("%lf",&a[j]);
		}
		sort(a+1,a+1+k);sum=0;
		for(j=2;j<k;j++){
			sum+=a[j];
		}
		ans[++cnt]=sum/ren;
	}
	sort(ans+1,ans+1+cnt);
	for(i=cnt-M+1;i<=cnt;i++){
		if(i==cnt)printf("%.3lf\n",ans[i]);
		else printf("%.3lf ",ans[i]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
