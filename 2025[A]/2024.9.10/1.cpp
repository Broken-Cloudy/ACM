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
