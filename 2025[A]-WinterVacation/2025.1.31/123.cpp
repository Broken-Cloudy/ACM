#include<bits/stdc++.h>
#define int long long
using namespace std;
int N,i,cnt;
double t[10009],sum,m;
string s,S[10009],ans[10009];
map<string,int>M;
signed main(){
	freopen("123.in","r",stdin);freopen("123.out","w",stdout);
	cin>>N;
	for(i=1;i<=N;i++){
		cin>>s;
		M[s]=1;
	}
	cin>>m;
	for(i=1;i<=m;i++){
		cin>>S[i];
		scanf("%lf",&t[i]);
		sum+=t[i];
	}
	sum/=m;
	for(i=1;i<=m;i++){
		if(M[S[i]]==0&&t[i]>sum){
			ans[++cnt]=S[i];
		}
	}
	if(cnt==0){
		cout<<"Bing Mei You"<<endl;
	}
	else{
		sort(ans+1,ans+1+cnt);
		for(i=1;i<=cnt;i++){
			cout<<ans[i]<<endl;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
