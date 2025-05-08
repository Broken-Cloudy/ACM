#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,k,ans,f,fff;
char c[3][200009];
bool ff=0;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);getchar();
		for(i=1;i<=n;i++)c[1][i]=getchar();getchar();
		for(i=1;i<=n;i++)c[2][i]=getchar();getchar();
		k=1;f=0;fff=0;
		for(i=1;i<=n;i++){
			if(c[1][i]=='x'&&c[2][i]=='x'){
				if(f==1){
					fff=1;
					f=0;
				}
			}
			else if(c[1][i]=='.'&&c[2][i]=='x'){
				if(c[2][i-1]=='.'&&c[1][i-1]=='x'){
					k++;
					f=1;
				}
				else{
					f=1;
				}
			}
			else if(c[2][i]=='.'&&c[1][i]=='x'){
				if(c[1][i-1]=='.'&&c[2][i-1]=='x'){
					k++;
					f=1;
				}
				else{
					f=1;
				}
			}
			else{
				f=1;
			}
			if(fff==1&&f==1){
				k++;
				fff=0;
			}
		}
		if(k>3||n<=2){
			printf("0\n");
			continue;
		}
		ans=0;
		if(c[1][1]=='.'){
			ff=0;
			if(c[1][2]=='.'&&c[2][1]=='.'&&c[2][2]=='x'){
				ff=1;
				if(k==2)ans++;
			}
			if(ff==0&&k==3&&(c[1][2]!='x'||c[2][1]!='x'))ans++;
		}
		if(c[2][1]=='.'){
			ff=0;
			if(c[1][1]=='.'&&c[1][2]=='x'&&c[2][2]=='.'){
				ff=1;
				if(k==2)ans++;
			}
			if(ff==0&&k==3&&(c[1][1]!='x'||c[2][2]!='x'))ans++;
		}
		if(c[1][n]=='.'){
			ff=0;
			if(c[1][n-1]=='.'&&c[2][n]=='.'&&c[2][n-1]=='x'){
				ff=1;
				if(k==2)ans++;
			}
			if(ff==0&&k==3&&(c[2][n]!='x'||c[1][n-1]!='x'))ans++;
		}
		if(c[2][n]=='.'){
			ff=0;
			if(c[1][n-1]=='x'&&c[1][n]=='.'&&c[2][n-1]=='.'){
				ff=1;
				if(k==2)ans++;
			}
			if(ff==0&&k==3&&(c[1][n]!='x'||c[2][n-1]!='x'))ans++;
		}
		for(i=2;i<n;i++){
			if(c[1][i]=='.'){
				ff=0;
				if(c[2][i]=='x'&&c[1][i-1]=='.'&&c[1][i+1]=='.'){
					if(k==2)ans++;
					ff=1;
				}
				else{
					if(c[2][i-1]=='x'&&c[2][i+1]=='x'){
						if(c[1][i-1]=='.'&&c[1][i+1]=='.'&&c[2][i]=='.'){
							if(k==1)ans++;ff=1;
						}
						else if(c[1][i-1]=='.'&&c[1][i+1]=='.'){
							if(k==2)ans++;ff=1;
						}
						else if(c[1][i+1]=='.'&&c[2][i]=='.'){
							if(k==2)ans++;ff=1;
						}
						else if(c[1][i-1]=='.'&&c[2][i]=='.'){
							if(k==2)ans++;ff=1;
						}
					}
					else if(c[2][i-1]=='.'&&c[2][i+1]=='x'){
						if(c[1][i+1]=='.'){
							if(k==2)ans++;
							ff=1;
						}
					}
					else if(c[2][i-1]=='x'&&c[2][i+1]=='.'){
						if(c[1][i-1]=='.'){
							if(k==2)ans++;
							ff=1;
						}
					}
				}
				if(ff==0&&k==3&&(c[2][i]!='x'||c[1][i-1]!='x'||c[1][i+1]!='x'))ans++;
			}
			if(c[2][i]=='.'){
				ff=0;
				if(c[1][i]=='x'&&c[2][i-1]=='.'&&c[2][i+1]=='.'){
					if(k==2)ans++;
					ff=1;
				}
				else{
					if(c[1][i-1]=='x'&&c[1][i+1]=='x'){
						if(c[2][i-1]=='.'&&c[2][i+1]=='.'&&c[1][i]=='.'){
							if(k==1)ans++;ff=1;
						}
						else if(c[2][i-1]=='.'&&c[2][i+1]=='.'){
							if(k==2)ans++;ff=1;
						}
						else if(c[2][i+1]=='.'&&c[1][i]=='.'){
							if(k==2)ans++;ff=1;
						}
						else if(c[2][i-1]=='.'&&c[1][i]=='.'){
							if(k==2)ans++;ff=1;
						}
					}
					else if(c[1][i-1]=='.'&&c[1][i+1]=='x'){
						if(c[2][i+1]=='.'){
							if(k==2)ans++;
							ff=1;
						}
					}
					else if(c[1][i-1]=='x'&&c[1][i+1]=='.'){
						if(c[2][i-1]=='.'){
							if(k==2)ans++;
							ff=1;
						}
					}
				}
				if(ff==0&&k==3&&(c[1][i]!='x'||c[2][i-1]!='x'||c[2][i+1]!='x'))ans++;
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
