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
	int t,s,i;//��Щ����a[]����� 
	for(i=1;i<=n;i++){
		if(!q.empty())t=q.back();s=0;
		while(!q.empty()&&a[t]>a[i]){//���������ѭ����������ɾ����һ���� 
			q.pop_back();
			s=t;//��¼��С,װ�������� 
			if(!q.empty()){//����д��ԭ����ǰ���һ�α���Ҫ����һ��q
				t=q.back();
			}
		}
		if(!q.empty()){//����С,������ĳ���������� 
			t=q.back();
			rc(t)=i;
		}
		if(s){//˵���޳�������,װ��һ�������� 
			lc(i)=s;
		}
		q.push_back(i);
	}
}
void dfs(int x){//�������
	printf("%lld ",x);
	if(lc(x))dfs(lc(x));
	if(rc(x))dfs(rc(x));
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%lld",&k),a[k]=i;
	build();
	int top=q.front();//top���Ǹ�
	dfs(top);
	fclose(stdin);fclose(stdout);
	return 0;
}
