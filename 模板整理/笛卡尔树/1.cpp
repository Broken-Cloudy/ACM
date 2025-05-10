#include<bits/stdc++.h>
#define int long long
#define lc(x) tree[x].ch[0]
#define rc(x) tree[x].ch[1]
using namespace std;
struct nod{
	int ch[2];
};
nod tree[10000009];
deque<int>q;
int n,i,a[10000009],cnt;
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
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	build();
	for(i=1;i<=n;i++){
		ansl^=(i*(lc(i)+1));
		ansr^=(i*(rc(i)+1));
	}
	cout<<ansl<<' '<<ansr<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
