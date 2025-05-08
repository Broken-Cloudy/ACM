#include<bits/stdc++.h>
using namespace std;
int a[1000100],version[1000100];
int vi,type,i,N,M,k,change,top;
struct nod{
	int l,r,val;
};
nod tree[4000100];
int updatenode(int node){//节点的更新 
	top++;
	tree[top]=tree[node];
	return top;
}
int build(int node,int start,int end){//建树其实就是新建节点的过程,与线段树略有不同 
	top++;node=top;
	if(start==end){
		tree[node].val=a[start];
		return top;
	} 
	int mid=(start+end)/2;
	tree[node].l=build(tree[node].l,start,mid);//左子树 
	tree[node].r=build(tree[node].r,mid+1,end);//右子树 
	return node;
}
int update(int node,int start,int end,int x,int val){//更新和线段树很像
	node=updatenode(node);//更新就要新建节点 
	if(start==end){
		tree[node].val=val;
	} 
	else{
		int mid=(start+end)/2;
		if(x<=mid){
			tree[node].l=update(tree[node].l,start,mid,x,val);//x是需要更新的位置 
		}
		else tree[node].r=update(tree[node].r,mid+1,end,x,val);
	}
	return node;
}
int ask(int node,int start,int end,int x){//x是需要询问的位置 
	if(start==end){
		return tree[node].val;
	}
	else{
		int mid=(start+end)/2;
		if(x<=mid){
			return ask(tree[node].l,start,mid,x);
		}
		else return ask(tree[node].r,mid+1,end,x);
	}
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>N>>M;
	for(i=1;i<=N;i++)scanf("%d",&a[i]);
	version[0]=build(0,1,N);//版本0 
	for(i=1;i<=M;i++){
		scanf("%d%d",&vi,&type);
		if(type==1){
			scanf("%d%d",&k,&change);
			version[i]=update(version[vi],1,N,k,change);
		}
		if(type==2){
			scanf("%d",&k);
			printf("%d\n",ask(version[vi],1,N,k));
			version[i]=version[vi];
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
