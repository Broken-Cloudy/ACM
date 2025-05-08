#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,k,num[35],sum,l,r,j,cc;
char c[1000009];
void putout(int x){
	int i;
	putchar(c[x]);
	for(i=1;i<=n;i++){
		if(i!=x)putchar(c[i]);
	}
	putchar('\n');
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);getchar();sum=0;
		for(i=1;i<=26;i++)num[i]=0;
		for(i=1;i<=n;i++){
			c[i]=getchar();
			num[c[i]-'a'+1]++;
		}
		for(i=1;i<=26;i++){
			if(k>sum&&k<=sum+num[i]){
				k-=sum;l=0;r=num[i]+1;cc=1;
				for(j=1;j<=n;j++){
					if(c[j]==(i+'a'-1)){
						if(j==n){
							putout(j);
							break;
						}
						if(c[j+1]>c[j]){//´ó 
							r-=cc;cc=1;
						}
						else if(c[j+1]<c[j]){
							l+=cc;cc=1;
						}
						else{
							cc++;
						}
						if(k<=l||k>=r){
							putout(j);
							break;
						}
					}
				}
				break;
			}
			else sum+=num[i];
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
