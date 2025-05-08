#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,K,k,i,j,c1,c2,X1,X2,Y1,Y2;
string s1,s2;
char cc;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>m>>K;s1="orz_Orz";s2="orz_Orz";
	for(i=1;i<=n;i++){
		getchar();
		for(j=1;j<=m;j++){
			string s;
			for(k=1;k<=K;k++){
				cc=getchar();
				s=s+cc;
			}
			if(s1==s){
				c1++;
			}
			else if(s2==s){
				c2++;
			}			
			else if(s1=="orz_Orz"){
				s1=s;c1++;X1=i;Y1=j;
			}
			else if(s2=="orz_Orz"){
				s2=s;c2++;X2=i;Y2=j;
			}
			
		}
	}
	if(c1==1){
		cout<<X1<<' '<<Y1<<endl;
	}
	if(c2==1){
		cout<<X2<<' '<<Y2<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
