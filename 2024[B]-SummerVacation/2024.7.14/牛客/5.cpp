#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[509][509],n,i,j,f[509][509],x,y,vis[509][509];
struct nod{
	int dian,num;
};
struct cmp{
	bool operator()(nod x,nod y){
		return x.num>y.num;
	}
};
priority_queue<nod,vector<nod>,cmp>q;
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	nod t,r;
	t.dian=1*1000+1;t.num=a[1][1];
	q.push(t);
	while(q.size()){
		t=q.top();q.pop();
		x=t.dian/1000;y=t.dian%1000;
		vis[x][y]=1;
		if(x==n&&y==n){
			cout<<t.num<<endl;
			break;
		}
		if(x+1<=n&&vis[x+1][y]==0){
			if(a[x+1][y]<=t.num){
				r.dian=(x+1)*1000+y;
				r.num=t.num;
				q.push(r);
			}
			else{
				r.dian=(x+1)*1000+y;
				r.num=a[x+1][y];
				q.push(r);
			}
		}
		if(y+1<=n&&vis[x][y+1]==0){
			if(a[x][y+1]<=t.num){
				r.dian=x*1000+y+1;
				r.num=t.num;
				q.push(r);
			}
			else{
				r.dian=x*1000+y+1;
				r.num=a[x][y+1];
				q.push(r);
			}
		}
		if(x-1>=1&&vis[x-1][y]==0){
			if(a[x-1][y]<=t.num){
				r.dian=(x-1)*1000+y;
				r.num=t.num;
				q.push(r);
			}
			else{
				r.dian=(x-1)*1000+y;
				r.num=a[x-1][y];
				q.push(r);
			}
		}
		if(y-1>=1&&vis[x][y-1]==0){
			if(a[x][y-1]<=t.num){
				r.dian=x*1000+y-1;
				r.num=t.num;
				q.push(r);
			}
			else{
				r.dian=x*1000+y-1;
				r.num=a[x][y-1];
				q.push(r);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
