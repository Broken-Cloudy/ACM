#include<iostream>
#include<cstdio>
using namespace std;
int tree[600009];
int op,x,y,n,m,i,a;
int lowbit(int x){
	return x&(-x);
}
//x是树的序号 k是权值 
void add(int x,int k){//建树 
	while(x<=n){
		tree[x]+=k;
		x+=lowbit(x);
	}
}
int sum(int x){//求和 
	int ans=0;
	while(x!=0){
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		add(i,a);
	}
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&op,&x,&y);
		if(op==1){
			add(x,y);
		}
		else{
			printf("%d\n",sum(y)-sum(x-1));
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
