#include<bits/stdc++.h>
#define int long long
using namespace std;
queue<int>ans,q;
struct nod{
	int val,bh;
};
struct cmp1{
	bool operator()(nod x,nod y){
		if(x.val==y.val)return x.bh>y.bh;
		else return x.val>y.val;//小顶 
	}
};
struct cmp2{
	bool operator()(nod x,nod y){
		if(x.val==y.val)return x.bh>y.bh;
		else return x.val<y.val;//大顶 
	}
};
priority_queue<nod,vector<nod>,cmp1>q1;//小顶 
priority_queue<nod,vector<nod>,cmp2>q2;//大顶 
int T,n,a[300009],i,b[300009],vis[300009],nowi,ANS,noww,p;
bool cmp(nod x,nod y){
	return x.val>y.val;
}
bool dfs(int l,int r,bool f){
	while(!q1.empty())q1.pop();while(!q2.empty())q2.pop();
	int i,j,L,R;
	nod t;
	for(i=l;i<=r;i++){
		t.bh=i;t.val=a[i];
		q1.push(t);q2.push(t);
	}
	i=l;
	bool fff;
	while(i<=r){
		while(vis[a[r]]==1&&!q.empty()){
			l=r+1;r=q.front();q.pop();noww=r;
			for(j=l;j<=r;j++){
				t.bh=j;t.val=a[j];
				q1.push(t);q2.push(t);
			}
		}
		fff=0;
		if(f==0){//找大 
			while(!q2.empty()){
				t=q2.top();q2.pop();
				if(vis[t.val]==0&&t.bh>=i){
					ans.push(t.val);
					vis[t.val]=1;
					i=t.bh+1;
					fff=1;f=!f;
					break;
				}
			}
			if(fff==0)break;
		}
		else{
			while(!q1.empty()){
				t=q1.top();q1.pop();
				if(vis[t.val]==0&&t.bh>=i){
					ans.push(t.val);
					vis[t.val]=1;
					i=t.bh+1;
					fff=1;f=!f;
					break;
				}
			}
			if(fff==0)break;
		}
		while(vis[a[r]]==1&&!q.empty()){
			l=r+1;r=q.front();q.pop();noww=r;
			for(j=l;j<=r;j++){
				t.bh=j;t.val=a[j];
				q1.push(t);q2.push(t);
			}
		}
	}
	return f;
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++)scanf("%lld",&a[i]),vis[i]=0;
		for(i=1;i<=n;i++)b[a[i]]++;
		for(i=1;i<=n;i++){
			if(b[a[i]]==1){
				q.push(i);
			}
			b[a[i]]--;
		}
		nowi=1;
		bool ff=0;//ff==0挑大的，ff==1挑小的 
		while(!q.empty()&&nowi<=n){
			int t=q.front();q.pop();noww=t;
			if(vis[a[t]]==0){
				ff=dfs(nowi,t,ff);
				nowi=noww+1;
				vis[a[t]]=1;
			}
		}
		int anss=ans.size();
		//printf("arr:: ",p);
		//for(i=1;i<=n;i++)printf("%lld ",a[i]);printf("\n");
		//printf("ans::%lld\n",p);
		printf("%lld\n",anss),p++;
		while(!ans.empty()){
			ANS=ans.front();ans.pop();
			printf("%lld ",ANS),p++;
		}
		printf("\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
