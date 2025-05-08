#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[200009],i,t,j,r;
int op[42];
int abss(int x){
	return max(x,-x);
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(i=29;i>=0;i--){
		op[++op[0]]=(1ll<<i);
	}
	op[++op[0]]=1;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(i=1;i<=op[0];i++){
			for(j=1;j<=n;j++){
				a[j]=abss(a[j]-op[i]);
			}
			for(j=1;j<=n;j++){
				if(a[j]>0){
					break;
				}
			}
			if(j==n+1){
				r=i;
				break;
			}
		}
		bool f=0;
		for(i=1;i<=n;i++){
			if(a[i]!=0){
				f=1;
				break;
			}
		}
		if(f==1){
			printf("-1\n");
			continue;
		}
		printf("%lld\n",r);
		for(i=1;i<=r;i++){
			if(i==r){
				printf("%lld\n",op[i]);
			}
			else printf("%lld ",op[i]);
		}
		if(op[0]==0)printf("\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
