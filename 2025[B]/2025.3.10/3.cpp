#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,n,b[400009],sum1,sum2,kk,L,R,ans[400009],anss;
map<int,int>M;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);M.clear();
		sum1=sum2=0;
		for(i=1;i<=2*n;i++){
			scanf("%lld",&b[i]);
			M[b[i]]=1;
		}
		sort(b+1,b+1+2*n);
		for(i=1;i<=n;i++){
			sum1+=b[i];
		}
		for(i=n+1;i<=2*n;i++){
			sum2+=b[i];
		}
		kk=sum2-sum1;
		if(M[kk]!=0){
			for(i=2*n;i>=n+1;i--){
				anss=2*b[i]+sum1-sum2;
				if(kk>0&&M[kk]==0){
					kk=b[i];b[i]=anss;
					M[kk]=0;
					break;
				}
			}
		}
		if(M[kk]!=0){
			kk=b[1];
			b[1]=2*b[1]+sum2-sum1;
			for(i=1;i<=n;i++)swap(b[i],b[i+n]);
		}
		ans[0]=2*n;
		for(i=2*n,j=1;i>=n+1;i--,j+=2)ans[j]=b[i];
		for(i=1,j=2;i<=n;i++,j+=2)ans[j]=b[i];
		printf("%lld ",kk);
		for(i=1;i<=ans[0];i++){
			if(i==ans[0])printf("%lld\n",ans[i]);
			else printf("%lld ",ans[i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
