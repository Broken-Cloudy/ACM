#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int u,v,next;
};
struct node{
	int x,y,z;
}op[400009];
nod a[400009];
map<int,map<int,int> >M;
int n,m,x,y,i,j,T,ans,du[100009],vis[100009],X[200009],Y[200009];
int gu[100009],dian[100009];
int fir[100009],cnt,ops;//2ÊÇÐÂÍ¼
bool FF;
void add(int x,int y){
	cnt++;
	a[cnt].next=fir[x];a[cnt].u=x;a[cnt].v=y;
	fir[x]=cnt;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);
		M.clear();ops=0;FF=0;gu[0]=0;dian[0]=0;
		for(i=0;i<=n;i++)du[i]=0,fir[i]=0,vis[i]=0;cnt=0;
		
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
