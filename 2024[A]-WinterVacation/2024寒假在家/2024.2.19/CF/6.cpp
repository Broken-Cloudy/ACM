#include<bits/stdc++.h>
using namespace std;
int T,i,j,a[9][9],ans,bass,x,y,num,rr;
char c[9][9];
bool b[9][9];
int main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(i=1;i<=7;i++){
			getchar();
			for(j=1;j<=7;j++){
				c[i][j]=getchar();
			}
		}
		for(i=1;i<=7;i++){
			for(j=1;j<=7;j++){
				if(c[i][j]=='B'){
					if(c[i-1][j-1]=='B'&&c[i+1][j+1]=='B'){
						if(c[i+1][j-1]=='B'&&c[i-1][j+1]=='B'){
							b[i][j]=1;
							a[i-1][j-1]++;
							a[i+1][j+1]++;
							a[i-1][j+1]++;
							a[i+1][j-1]++;
						}
					}
				}
			}
		}
		ans=0;
		while(true){
			bass=0;
			for(i=1;i<=7;i++){
				for(j=1;j<=7;j++){
					if(a[i][j]>=bass){
						if(a[i][j]==bass)num++;
						else num=1;
						bass=a[i][j];
					}
				}
			}
			int number=0;
			for(i=1;i<=7;i++){
				if(number==(num+1)/2){
					break;
				}
				for(j=1;j<=7;j++){
					if(a[i][j]==bass){
						number++;
						if(number==(num+1)/2){
							x=i;y=j;
							break;
						}
					}
				}
			}
			if(bass==0)break;
			c[x][y]='W';
			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
			for(i=1;i<=7;i++){
				for(j=1;j<=7;j++){
					if(c[i][j]=='B'){
						if(c[i-1][j-1]=='B'&&c[i+1][j+1]=='B'){
							if(c[i+1][j-1]=='B'&&c[i-1][j+1]=='B'){
								b[i][j]=1;
								a[i-1][j-1]++;
								a[i+1][j+1]++;
								a[i-1][j+1]++;
								a[i+1][j-1]++;
							}
						}
					}
				}
			}
			ans++;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
