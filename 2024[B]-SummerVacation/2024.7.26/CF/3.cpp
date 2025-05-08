#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ans,i,j,k,q,l,r,h1[200009][31],h2[200009][31];
int c[31],d[31];
queue<int>qq;
char a[200009],b[200009];
int abss(int x){
	return max(x,-x);
}
int check(int l,int r){
	int ans=0;
	int i;
	for(i=1;i<=28;i++){
		c[i]=h1[r][i]-h1[l][i];
		d[i]=h2[r][i]-h2[l][i];
	}
	for(i=1;i<=28;i++){
		ans+=abss(c[i]-d[i]);
	}
	ans/=2;
	return ans;
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld%lld",&n,&q);
		for(i=1;i<=n;i++){
			for(j=0;j<=28;j++){
				h1[i][j]=h2[i][j]=0;
			}
		}
		getchar();for(i=1;i<=n;i++)a[i]=getchar();
		getchar();for(i=1;i<=n;i++)b[i]=getchar();
		for(i=1;i<=n;i++){
			for(j=1;j<=28;j++){
				h1[i][j]=h1[i-1][j];
				h2[i][j]=h2[i-1][j];
			}
			h1[i][a[i]-'a'+1]++;
			h2[i][b[i]-'a'+1]++;
		}
		for(i=1;i<=q;i++){
			scanf("%lld%lld",&l,&r);
			printf("%lld\n",check(l-1,r));
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
