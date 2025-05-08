#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int i,a[9][9],j,k,ans;
bool f[9][9];//0 is broken
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(i=0;i<len;i++){
		a[i/4+1][i%4+1]=(s[i]-'0');
	}
	//i=2,4
	ans=0;i=2;for(j=1;j<=4;j++)if(a[i][j])ans++;i=4;for(j=1;j<=4;j++)if(a[i][j])ans++;
	if(ans%2==0){i=2;for(j=1;j<=4;j++)f[i][j]=1;i=4;for(j=1;j<=4;j++)f[i][j]=1;}
	else{i=1;for(j=1;j<=4;j++)f[i][j]=1;i=3;for(j=1;j<=4;j++)f[i][j]=1;}
	//i=3,4
	ans=0;i=3;for(j=1;j<=4;j++)if(a[i][j])ans++;i=4;for(j=1;j<=4;j++)if(a[i][j])ans++;
	if(ans%2==0){i=3;for(j=1;j<=4;j++)f[i][j]=1;i=4;for(j=1;j<=4;j++)f[i][j]=1;}
	else{i=1;for(j=1;j<=4;j++)f[i][j]=1;i=2;for(j=1;j<=4;j++)f[i][j]=1;}
	//j=2,4
	ans=0;j=2;for(i=1;i<=4;i++)if(a[i][j])ans++;j=4;for(i=1;i<=4;i++)if(a[i][j])ans++;
	if(ans%2==0){j=2;for(i=1;i<=4;i++)f[i][j]=1;j=4;for(i=1;i<=4;i++)f[i][j]=1;}
	else{j=1;for(i=1;i<=4;i++)f[i][j]=1;j=3;for(i=1;i<=4;i++)f[i][j]=1;}
	//j=3,4
	ans=0;j=3;for(i=1;i<=4;i++)if(a[i][j])ans++;j=4;for(i=1;i<=4;i++)if(a[i][j])ans++;
	if(ans%2==0){j=3;for(i=1;i<=4;i++)f[i][j]=1;j=4;for(i=1;i<=4;i++)f[i][j]=1;}
	else{j=1;for(i=1;i<=4;i++)f[i][j]=1;j=2;for(i=1;i<=4;i++)f[i][j]=1;}
	for(i=1;i<=4;i++){
		for(j=1;j<=4;j++){
			if(f[i][j]==0){
				ans=(i-1)*4+j;
			}
		}
	}
	cout<<ans-1<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
