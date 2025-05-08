#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,a[100009],anss,GCD,t;
queue<int>q;
void gcd(int a,int b){
	if(b==0){
		GCD=a;
		return;
	}
	gcd(b,a%b);
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		while(!q.empty())q.pop();
		scanf("%lld",&n);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(n==2){
			if(a[1]!=a[2])printf("No\n");
			else printf("Yes\n");
		}
		else{
			sort(a+1,a+1+n);anss=a[1];
			for(i=2;i<=n;i++){
				if(a[i]%anss==0){
					q.push((a[i]/anss));
				}
			}
			if(q.size()==0){
				printf("No\n");
				continue;
			}
			else{
				GCD=q.front();q.pop();
			}
			while(!q.empty()){
				t=q.front();q.pop();
				gcd(t,GCD);
			}
			if(GCD==1)printf("Yes\n");
			else printf("No\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
