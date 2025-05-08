#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,vis[200009],i,X[200009],n,poi,yoi,x,y;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++)vis[i]=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&X[i]);
			vis[X[i]]++;
		}
		poi=0;
		for(i=1;i<=n;i++){
			if(vis[i]==0)poi=i;
			else yoi=i;
		}
		if(poi!=0){
			printf("? %lld %lld\n",poi,yoi);fflush(stdout);
			scanf("%lld",&x);
			if(x==0){
				printf("! A\n");fflush(stdout);
			}
			else{
				printf("! B\n");fflush(stdout);
			}
		}
		else{
			for(i=1;i<=n;i++){
				if(X[i]==1)poi=i;
				else if(X[i]==n)yoi=i;
			}
			printf("? %lld %lld\n",poi,yoi);fflush(stdout);
			scanf("%lld",&x);
			printf("? %lld %lld\n",yoi,poi);fflush(stdout);
			scanf("%lld",&y);
			if(x==y&&x>=(n-1)&&y>=(n-1)){
				printf("! B\n");fflush(stdout);
			}
			else{
				printf("! A\n");fflush(stdout);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
