#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int bh,val;
}a[200009],t;
int n,m,k,i,j,u,v,ans[200009];
bool cmp(nod x,nod y){
	return x.val>y.val;
}
struct cmp2{
	bool operator()(nod x,nod y){
		return x.val<y.val;
	}
};
priority_queue<nod,vector<nod>,cmp2>q;
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++){
		scanf("%lld",&a[i].val);
		a[i].bh=i;
		q.push(a[i]);
	}
	sort(a+1,a+1+m,cmp);
	if(a[1].val<=(n-n/(k+1))){
		while(q.size()>=2){
			nod t1=q.top();q.pop();
			nod t2=q.top();q.pop();
			for(i=1;i<=k;i++){
				if(t1.val==0||t1.val<t2.val)break;
				else{
					t1.val--;
					ans[++ans[0]]=t1.bh;
				}
			}
			t2.val--;
			ans[++ans[0]]=t2.bh;
			if(t1.val>0)q.push(t1);
			if(t2.val>0)q.push(t2);
		}
		if(!q.empty())t=q.top();
		else{
			t.val=0;
		}
		while(t.val>0){ans[++ans[0]]=t.bh;t.val--;}
		for(i=1;i<=ans[0];i++)printf("%lld ",ans[i]);
	}
	else cout<<-1<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
