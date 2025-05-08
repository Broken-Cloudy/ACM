#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,k,z,r,ans;
char a[200009];
queue<int>q1;
queue<int>q2;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		z=r=0;ans=0;
		while(!q1.empty())q1.pop();while(!q2.empty())q2.pop();
		scanf("%lld",&n);getchar();
		for(i=1;i<=n;i++)a[i]=getchar();
		for(i=1;i<=n;i+=2){
			int len=i/2;
			if(a[i+1]==')'){
				if(z>0){
					a[i]=')';
					z--;
					continue;
				}
				a[i]='(';
			}
			else{
				if(z>0){
					a[i]=')';
					continue;
				}
				a[i]='(';
				z++;
			}
		}
		for(i=1;i<=n;i++){
			if(a[i]=='('){
				if(q2.empty()){
					q1.push(i);
				}
				else{
					int t=q2.front();
					q2.pop();
					ans+=(i-t);
				}
			}
			else{
				if(q1.empty()){
					q2.push(i);
				}
				else{
					int t=q1.front();
					q1.pop();
					ans+=(i-t);
				}
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
