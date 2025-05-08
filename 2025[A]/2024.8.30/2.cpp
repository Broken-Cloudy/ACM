#include<bits/stdc++.h>
#define int long long
using namespace std;
string s,ss[100009];
int n,i,cnt,ans;
bool f=0;
map<string,int>m;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	ans=n/2;
	for(i=1;i<=n;i++){
		cin>>s;
		if(m[s]==0){
			m[s]=1;
			ss[++cnt]=s;
		}
		else m[s]+=1;
	}
	for(i=1;i<=cnt;i++){
		if(m[ss[i]]>ans){
			cout<<ss[i]<<endl;
			f=1;
			break;
		}
	}
	if(f==0)cout<<"uh-oh"<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
