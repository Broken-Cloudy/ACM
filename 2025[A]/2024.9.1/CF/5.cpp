#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,j,ans;
int ji[200009][28],ou[200009][28];
int jiend[28],ouend[28];
int jimax,oumax;
char a[200009];
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);getchar();
		for(i=1;i<=n;i++)a[i]=getchar();
		ans=1000000009;
		if(n%2==1){//必须删掉一个 
			for(i=1;i<=n;i++){
				int t=(i+1)/2;
				if(i%2==0){
					ou[t][a[i]-'a'+1]++;
					for(j=1;j<=26;j++){
						ou[t][j]+=ou[t-1][j];
					}
				}
				else{
					ji[t][a[i]-'a'+1]++;
					for(j=1;j<=26;j++){
						ji[t][j]+=ji[t-1][j];
					}
				} 
			}
			for(i=1;i<=n;i++){//处理掉一个 
				int t=(i+1)/2;
				if(i%2==1){
					for(j=1;j<=26;j++)jiend[j]=ouend[j]=0;
					for(j=1;j<=26;j++){
						jiend[j]=ji[i/2][j];
						ouend[j]=ou[i/2][j];
					}
					for(j=1;j<=26;j++){
						jiend[j]+=(ou[n/2][j]-ou[i/2][j]);//除掉自己
						ouend[j]+=(ji[(n+1)/2][j]-ji[t][j]);
					}
					jimax=oumax=0;
					for(j=1;j<=26;j++){
						jimax=max(jimax,jiend[j]);
						oumax=max(oumax,ouend[j]);
					}
					ans=min(ans,(n/2-jimax)+(n/2-oumax));
				}
				else{
					for(j=1;j<=26;j++)jiend[j]=ouend[j]=0;
					for(j=1;j<=26;j++){
						jiend[j]=ji[i/2][j];
						ouend[j]=ou[i/2][j];
					}
					ouend[a[i]-'a'+1]--;
					for(j=1;j<=26;j++){
						jiend[j]+=(ou[n/2][j]-ou[t][j]);
						ouend[j]+=(ji[(n+1)/2][j]-ji[i/2][j]);//除掉自己 
					}
					jimax=oumax=0;
					for(j=1;j<=26;j++){
						jimax=max(jimax,jiend[j]);
						oumax=max(oumax,ouend[j]);
					}
					ans=min(ans,(n/2-jimax)+(n/2-oumax));
				}
			}
			ans++;
		}
		else{
			for(i=1;i<=n;i++){
				int t=(i+1)/2;
				if(i%2==0){
					ou[t][a[i]-'a'+1]++;
					for(j=1;j<=26;j++){
						ou[t][j]+=ou[t-1][j];
					}
				}
				else{
					ji[t][a[i]-'a'+1]++;
					for(j=1;j<=26;j++){
						ji[t][j]+=ji[t-1][j];
					}
				} 
			}
			jimax=oumax=0;
			for(j=1;j<=26;j++){
				jimax=max(jimax,ji[n/2][j]);
				oumax=max(oumax,ou[n/2][j]);
			}
			ans=(n/2-jimax)+(n/2-oumax);
		}
		printf("%lld\n",ans);
		for(i=1;i<=n;i++)for(j=1;j<=26;j++)ji[i][j]=ou[i][j]=0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
