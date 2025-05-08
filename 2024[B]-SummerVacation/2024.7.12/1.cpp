#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,a[200009],i,ans,x,b[200009],cnt,j;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld%lld",&n,&x);ans=0;cnt=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		ans++;
		map<int,int>m;
		m[x]=1;b[++cnt]=x;
		for(i=1;i<=n;i++){
			if(x%a[i]==0&&a[i]!=1){
				if(m[a[i]]==1){
					m.clear();
					m[x]=1;
					cnt=0;
					b[++cnt]=x;
					b[++cnt]=x/a[i];
					m[x/a[i]]=1;
					ans++;
				}
				else{
					int num=cnt;
					for(j=1;j<=num;j++){
						if(b[j]%a[i]==0){
							if(m[b[j]/a[i]]==0){
								m[b[j]/a[i]]=1;
								b[++cnt]=b[j]/a[i];
							}
						}
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
