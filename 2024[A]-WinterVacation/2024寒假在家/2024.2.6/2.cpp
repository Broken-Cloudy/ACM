#include<bits/stdc++.h>
using namespace std;
int T,i,n,k,ans,b[29],cnt,j;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d",&n);cnt=0;
		memset(b,0,sizeof(b));
		for(i=1;i<=n;i++){
			scanf("%d",&k);
			if(k==0){
				b[++cnt]=0;
				putchar('a'+cnt-1);
			}
			else{
				for(j=1;j<=26;j++){
					if(b[j]==k-1){
						b[j]++;
						putchar('a'+j-1);
						break;
					}
				}
			}
		}
		putchar('\n');
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
