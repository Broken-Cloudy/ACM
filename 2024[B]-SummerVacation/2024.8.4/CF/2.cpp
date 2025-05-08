#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,k,i,ans,ou,ji,oun,jin,a[200009];
int f=0;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);f=0;ji=0;ou=0;jin=0;oun=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&k);
			if(k%2==1){
				jin++;
				ji=max(k,ji);
				if(f==0||f==1)f=1;
				else f=3;
			}
			else{
				oun++;
				a[oun]=k;
				ou=max(k,ou);
				if(f==0||f==2)f=2;
				else f=3;
			}
		}
		if(f<3){
			printf("0\n");
			continue;
		}
		sort(a+1,a+1+oun);
		if(ji>ou){
			printf("%lld\n",oun);
		}
		else{
			ans=oun;
			for(i=1;i<=oun;i++){
				if(ji>a[i]){
					ji=max(ji,ji+a[i]);
				}
				else ans=oun+1;
			}
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
