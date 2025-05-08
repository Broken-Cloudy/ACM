#include<bits/stdc++.h>
using namespace std;
char a[509][509];
int n,m,i,j,si,x,y,ans,me[509][509];
int main(){
	freopen("7.in","r",stdin);freopen("7.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		getchar();
		for(j=1;j<=m;j++){
			a[i][j]=getchar();
			if(a[i][j]=='*')me[i][j]=me[i][j-1]+1;
			else me[i][j]=me[i][j-1];
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i][j]=='*'){
				si=1;
				while((j-si)>=1&&(j+si)<=m&&(i+si)<=n){
					x=i+si;
					if(me[x][j+si]-me[x][j-si-1]==2*si+1)ans++;
					if(a[x][j-si]=='.'||a[x][j+si]=='.')break;
					else si++;
				}
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
