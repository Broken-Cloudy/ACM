#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,b[1009],i,j,ans,k;
struct nod{
	int x,y;
};
nod a[1009];
signed main(){
	freopen("11.in","r",stdin);freopen("11.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%lld",&b[i]);
	for(i=1;i<=n;i++){
		if(b[i]==i)continue;
		for(j=i;j<=n;j++){
			if(b[j]==i){
				ans++;
				a[ans].x=i;
				a[ans].y=j;
				for(k=0;k<=j-i;k++)if((i+k)<=(j-k))swap(b[i+k],b[j-k]);
				break;
			}
		}
	}
	cout<<ans<<endl;
	for(i=1;i<=ans;i++){
		printf("%lld %lld\n",a[i].x,a[i].y);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
