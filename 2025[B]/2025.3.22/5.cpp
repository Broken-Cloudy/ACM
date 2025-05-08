#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,j,p,n,a[10009],b[10009],ton[1000009],maxx,d[10009],k,last;
bool f=0;
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);maxx=-1;d[0]=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++)scanf("%lld",&b[i]),ton[b[i]]++;
		sort(a+1,a+1+n);f=0;
		for(i=1;i<=n;i++){//10000
			if(ton[a[i]]>0&&f==0){
				ton[a[i]]--;
			}
			else{
				f=1;
				d[++d[0]]=a[i];
				if(maxx==-1){
					k=i-1;last=1;
					maxx=a[i];
				}
				while(maxx>0){
					for(j=k;j>=1;j--){
						if(a[j]>=maxx){
							d[++d[0]]=a[j];
							ton[a[j]]++;
						}
						else{
							k=j;
							break;
						}
					}
					for(j=1;j<=d[0];j+=max((d[0]-1)/1000,1LL)){
						if(ton[d[j]%maxx]>0){
							ton[d[j]%maxx]--;
						}
						else{
							ton[d[j]%maxx]--;
							for(p=j;p>=1;p-=max((d[0]-1)/1000,1LL)){
								ton[d[p]%maxx]++;
							}
							break;
						}
					}
					if(j>d[0]){
						break;
					}
					else{
						maxx--;
					}
				}
			}
		}
		if(maxx==0)printf("-1\n");
		else if(maxx==-1)printf("12345678\n");
		else printf("%lld\n",maxx);
		for(i=1;i<=n;i++)ton[b[i]]=0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
