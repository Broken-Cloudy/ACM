#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100009],b[100009],i,n,q,k,Sum[100009],cnt=1,sum,j,M,m,x,y,z,ii=1;
struct nod{
	int dx,bh;
}mini;
struct cmp{
	bool operator()(nod x,nod y){
		return x.dx<y.dx;
	}
};
bool f[100009];
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n>>q;
	priority_queue<nod,vector<nod>,cmp>d;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%lld",&b[i]);
	}
	i=1;
	while(cnt<=n){
		for(int o=ii;o<i;o++){
			if(f[o]==0){
				nod y;
				y.dx=b[o];
				y.bh=o;
				d.push(y);
			}
		}
		mini.dx=-1;ii=i;
		if(!d.empty())mini=d.top();
		j=i;sum=0;M=1e18+9;
		while(j<=n){
			sum+=a[j];
			m=sum+b[j];
			if(m<M){
				M=m;
				i=j+1;
			}
			if(sum>=M||(sum>=mini.dx&&mini.dx>0)){
				if(sum>=M){
					Sum[cnt]=Sum[cnt-1]+M;
					f[i-1]=1;
				}
				else{
					Sum[cnt]=Sum[cnt-1]+mini.dx;
					f[mini.bh]=1;
					d.pop();
				}
				break;
			}
			j++;
		}
		cnt++;
	}
	for(i=1;i<=q;i++){
		scanf("%lld",&k);
		printf("%lld\n",Sum[k]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
