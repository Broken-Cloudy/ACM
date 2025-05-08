#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,k,a[200009];
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	a[1]=1;a[10]=1;a[26]=1;a[27]=2;a[23]=2;
	a[2]=a[3]=3;a[4]=a[5]=4;a[6]=a[7]=5;a[8]=a[9]=6;
	a[12]=a[11]=7;a[14]=a[13]=8;a[16]=a[15]=9;a[18]=a[17]=10;
	a[20]=a[19]=11;a[22]=a[21]=12;a[25]=a[24]=13;
	while(T--){
		scanf("%lld",&n);
		if(n%2==0){
			for(i=1;i<=n;i++){
				if(i==n)printf("%lld\n",(i+1)/2);
				else printf("%lld ",(i+1)/2);
			}
		}
		else{
			if(n<27){
				printf("-1\n");
			}
			else{
				for(i=28;i<=n;i++){
					a[i]=i/2;
				}
				for(i=1;i<=n;i++){
					if(i==n)printf("%lld\n",a[i]);
					else printf("%lld ",a[i]);
				}
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
