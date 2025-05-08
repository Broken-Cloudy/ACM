#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,a[200009],j,k;
string s;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>s;
		int len=s.length();
		for(i=0;i<len;i++){
			a[i+1]=s[i]-'0';
		}
		for(i=1;i<=len;i++){
			for(j=max(1LL,i-a[i]+1);j<i;j++){
				if(a[i]-(i-j)>a[j]){
					a[i]-=(i-j);
					for(k=i-1;k>=j;k--){
						swap(a[k+1],a[k]);
					}
					break;
				}
			}
		}
		for(i=1;i<=len;i++){
			printf("%lld",a[i]);
		}
		printf("\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
