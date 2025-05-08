#include<bits/stdc++.h>
using namespace std;
int n,i,ans,sum,t;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>t;
	for(n=1;n<=t;n++){
		ans=0;
		map<int,int>m;
		for(i=0;i<=n-1;i++){//m
			int k=n/(i+1);
			if(m[k]==1){
				continue;
			}
			else{
				m[k]=1;
				ans++;
			}
		}
		sum+=ans;
	}
	cout<<sum<<' ';
	fclose(stdin);fclose(stdout);
	return 0;
}
