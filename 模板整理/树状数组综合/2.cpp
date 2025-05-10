#include<bits/stdc++.h>
using namespace std;
int op,n,m,x,y,k,i;
int tree[500009],a[500009];
int lowbit(int x){
	return x&(-x);
}
void add(int x,int k){
	int ans=0,y=x;
	while(x<=n){
		ans+=tree[x];
		x+=lowbit(x);
	}
	tree[y]=k-ans;
}
void change(int node,int k){
	while(node>0){
		tree[node]+=k;
		node-=lowbit(node);
	}
}
int check(int x){
	int ans=0;
	while(x<=n){
		ans+=tree[x];
		x+=lowbit(x);
	}
	return ans;
}
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		
	}
	for(i=n;i>=1;i--){
		add(i,a[i]);
	}
	for(i=1;i<=m;i++){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d%d",&x,&y,&k);
			change(y,k);
			change(x-1,-k);
		}
		else{
			scanf("%d",&x);
			printf("%d\n",check(x));
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
