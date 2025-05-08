#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,a[59],f1,f2,f3;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;f1=f2=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++){
			if(a[i]>0){
				if(f1==0)f1=1;
				else if(f1==1&&f2==-1)f2=1;
			}
			else{
				if(f1==1&&f2==0)f2=-1;
			}
		}
		if(f1==1&&f2==1)printf("2\n");
		else if(f1==1)printf("1\n");
		else printf("0\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
