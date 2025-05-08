#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
struct nod{
	int next,u,v;
};
struct Time{
	int in_time,out_time;
};
Time A[300009];
nod a[600009];
int fir[300009],cnt,vis[300009],x,y,timer,wrong;
void add(int u,int v){
	cnt++;
	a[cnt].next=fir[u];
	a[cnt].u=u;a[cnt].v=v;
	fir[u]=cnt;
}
int T,i,k,n,q,b[300009],p[300009];
void dfs(int x){
	int i;
	vis[x]=1;
	A[x].in_time=++timer;
	for(i=fir[x];i;i=a[i].next){
		int y=a[i].v;
		if(vis[y]==0){
			dfs(y);
		}
	}
	A[x].out_time=++timer;
}
bool checker2(int x){
	if(A[p[x]].in_time<=A[p[x+1]].in_time&&A[p[x]].out_time>=A[p[x+1]].out_time)return 1;
	else return 0;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&q);cnt=0;
		for(i=1;i<=n;i++)fir[i]=0,vis[i]=0;
		for(i=1;i<n;i++){
			scanf("%lld",&k);
			add(i+1,k);add(k,i+1);
		}
		timer=0;
		dfs(1);
		for(i=1;i<=n;i++){
			scanf("%lld",&p[i]);
		}
		wrong=0;
		for(i=1;i<n;i++){
			if(checker2(i)==0)wrong++;
		}
		while(q--){
			scanf("%lld%lld",&x,&y);
			if(x-1>=1){
				if(checker2(x-1)==1){
					swap(p[x],p[y]);
					if(checker2(x-1)==0){
						wrong++;
					}
					swap(p[x],p[y]);
				}
				else{
					swap(p[x],p[y]);
					if(checker2(x-1)==1){
						wrong--;
					}
					swap(p[x],p[y]);
				}
			}
			if(x+1<=n){
				if(checker2(x)==1){
					swap(p[x],p[y]);
					if(checker2(x)==0){
						wrong++;
					}
					swap(p[x],p[y]);
				}
				else{
					swap(p[x],p[y]);
					if(checker2(x)==1){
						wrong--;
					}
					swap(p[x],p[y]);
				}
			}
			if(y-1>=1){
				if(checker2(y-1)==1){
					swap(p[x],p[y]);
					if(checker2(y-1)==0){
						wrong++;
					}
					swap(p[x],p[y]);
				}
				else{
					swap(p[x],p[y]);
					if(checker2(y-1)==1){
						wrong--;
					}
					swap(p[x],p[y]);
				}
			}
			if(y+1<=n){
				if(checker2(y+1)==1){
					swap(p[x],p[y]);
					if(checker2(y+1)==0){
						wrong++;
					}
					swap(p[x],p[y]);
				}
				else{
					swap(p[x],p[y]);
					if(checker2(y+1)==1){
						wrong--;
					}
					swap(p[x],p[y]);
				}
			}
			if(wrong==0){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
			swap(p[x],p[y]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
