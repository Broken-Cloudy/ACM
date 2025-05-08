#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,i,len,ans;
map<char,int>M;
char a[200009],b[200009];
signed main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);M.clear();ans=0;
		getchar();for(i=1;i<=n;i++)a[i]=getchar();
		getchar();for(i=1;i<=m;i++)b[i]=getchar();
		if(n>=m){//a´ó 
			for(i=1;i<=n;i++){
				M[a[i]]+=1;
			}
			for(i=1;i<=m;i++){
				if(M[b[i]]>0){
					M[b[i]]--;
				}
				else{
					ans++;
				}
			}
			len=n-m;len/=2;
			for(i='a';i<='z';i++){
				while(M[i]>=2&&len>0){
					M[i]-=2;
					len--;
				}
			}
			ans+=len;
		}
		else{//b´ó 
			for(i=1;i<=m;i++){
				M[b[i]]+=1;
			}
			for(i=1;i<=n;i++){
				if(M[a[i]]>0){
					M[a[i]]--;
				}
				else{
					ans++;
				}
			}
			len=m-n;len/=2;
			for(i='a';i<='z';i++){
				while(M[i]>=2&&len>0){
					M[i]-=2;
					len--;
				}
			}
			ans+=len;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
