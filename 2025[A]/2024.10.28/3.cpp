#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,C1,C0,ans,t,ANS;
char c[400009];
queue<int>q;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		while(!q.empty())q.pop();
		scanf("%lld",&n);getchar();ans=0;
		for(i=1;i<=n;i++)c[i]=getchar();
		for(i=n;i>=1;i--){
			if(q.size()>=i){
				while(!q.empty()&&i>0){
					i--;
					t=q.front();q.pop();
					ans+=t;
				}
				break;
			}
			if(c[i]=='1'){
				q.push(i);
			}
			else{
				if(!q.empty()){
					t=q.front();q.pop();
					ans+=t;
				}
			}
		}
		ANS=n*(n+1)/2-ans;
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
