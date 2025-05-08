#include<bits/stdc++.h>
using namespace std;
char s[200009],c[99];
int n,k,i,zuo,you,rem[200009],j;
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n>>k;
	scanf("%s",s+1);
	for(i=1;i<=n;i++){
		if(s[i]=='I'){
			zuo=i-1;
			you=i+1;
			for(j=1;j<=zuo;j++){
				rem[j]=j-1;
			}
			for(j=you;j<=n+1;j++){
				rem[j]=j+1;
			}
			break;
		}
	}
	for(i=1;i<=k;i++){
		scanf("%s",c+1);
		if(c[1]=='<'){//×óÒÆ 
			int t=zuo;
			zuo=rem[zuo];
			rem[t]=you;
		}
		else if(c[1]=='-'){//ÓÒÒÆ 
			int t=you;
			you=rem[you];
			rem[t]=zuo;
		}
		else if(c[1]=='b'){//³¬¼¶É¾³ý 
			if(zuo>0){
				if(you<=n&&s[you]==')'&&s[zuo]=='('){
					int t=you;
					you=rem[you];
					rem[t]=rem[you];
				}
				int t=zuo;
				zuo=rem[zuo];
				rem[t]=rem[zuo];
			}
		}
		else{
			if(you<=n){
				int t=you;
				you=rem[you];
				rem[t]=rem[you];
			}
		}
	}
	for(i=rem[zuo];i;i=rem[i]){
		putchar(s[i]);
	}
	putchar('I');
	for(i=rem[you];i<=n;i=rem[i]){
		putchar(s[i]);
	}
	putchar('\n');
	fclose(stdin);fclose(stdout);
	return 0;
}
