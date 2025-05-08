#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,len[100009],k[31],GCD,m,j,sum,ans,ANS;
void gcd(int a,int b){
	if(b==0){
		GCD=a;
	}
	else gcd(b,a%b);
}
string s[100009],S;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)cin>>s[i],S+=s[i];
	for(i=1;i<=n;i++)len[i]=s[i].length(),m+=len[i];
	GCD=len[1];for(i=2;i<=n;i++)gcd(GCD,len[i]);
	for(j=1;j<=GCD;j++){
		memset(k,0,sizeof(k));sum=0;
		for(i=j-1;i<m;i+=GCD){
			k[S[i]-'a'+1]++;
			sum++;
		}
		ans=sum;
		for(i=1;i<=26;i++){
			ans=min(ans,sum-k[i]);
		}
		ANS+=ans;
	}
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
