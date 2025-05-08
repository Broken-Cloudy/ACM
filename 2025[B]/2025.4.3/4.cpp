#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int x;
}d[200009],t;
queue<nod>q;
int T,i,a[28],sum,n,m,cnt,x,j,f[250009];
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		sum=0;
		for(i=1;i<=26;i++){
			scanf("%lld",&a[i]);
			sum+=a[i];
		}
		n=(sum+1)/2;//奇数位 
		m=sum/2;//偶数位 
		cnt++;d[cnt].x=0;
		for(i=1;i<=26;i++){//26
			for(j=1;j<=cnt;j++){//150000
				x=d[j].x;
				if(x+a[i]<=n){
					if(f[x+a[i]]==0){
						f[x+a[i]]=i;
						t.x=x+a[i];
						q.push(t);
					}
				}
			}
			while(!q.empty()){
				t=q.front();q.pop();
				d[++cnt]=t;
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
