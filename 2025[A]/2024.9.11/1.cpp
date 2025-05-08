#include<bits/stdc++.h>
#define int long long
#define lc(x) tree[x].ch[0]
#define rc(x) tree[x].ch[1]
using namespace std;
struct nod{
	int ch[2];
};
nod tree[100009];
deque<int>q;
int n,i,a[100009],cnt,k;
long long ansl,ansr;
void build(){
	int t,s,i;//这些都是a[]的序号 
	for(i=1;i<=n;i++){
		if(!q.empty())t=q.back();s=0;
		while(!q.empty()&&a[t]>a[i]){//进入了这层循环，就至少删除了一个数 
			q.pop_back();
			s=t;//记录次小,装在左子树 
			if(!q.empty()){//这样写的原因是前面第一次必须要调用一次q
				t=q.back();
			}
		}
		if(!q.empty()){//不够小,它连在某个右子树上 
			t=q.back();
			rc(t)=i;
		}
		if(s){//说明剔除过数字,装配一下左子树 
			lc(i)=s;
		}
		q.push_back(i);
	}
}
void dfs(int x){//先序遍历
	printf("%lld ",x);
	if(lc(x))dfs(lc(x));
	if(rc(x))dfs(rc(x));
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%lld",&k),a[k]=i;
	build();
	int top=q.front();//top就是根
	dfs(top);
	fclose(stdin);fclose(stdout);
	return 0;
}
