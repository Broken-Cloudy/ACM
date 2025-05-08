#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,k1,k2,p1,p2;
char a[200009],b[200009];
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);k1=k2=0;
		getchar();for(i=1;i<=n;i++)a[i]=getchar();
		getchar();for(i=1;i<=n;i++)b[i]=getchar();
		for(i=1;i<=n;i++){
			if(i%2==1){//a
				if(a[i]=='0')k1++;
			}
			else{//b
				if(b[i]=='0')k1++;
			}
		}
		for(i=1;i<=n;i++){
			if(i%2==1){//a
				if(b[i]=='0')k2++;
			}
			else{//b
				if(a[i]=='0')k2++;
			}
		}
		p1=(n+1)/2;p2=n/2;
		if(k1>=p1&&k2>=p2)printf("YES\n");
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
