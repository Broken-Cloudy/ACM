#include<bits/stdc++.h>
using namespace std;
int n,i,j=1,q,tree[1000009],k,a[1000009];
struct nod{
	int l,r;
	int bh,sum;
};
nod ask[1000009];
bool cmp(nod x,nod y){
	return x.r<y.r;
}
bool cmp2(nod x,nod y){
	return x.bh<y.bh;
}
map<int,int>m;
int lowbit(int x){
	return x&(-x);
}
void add(int x,int k){
	while(x<=n){
		tree[x]+=k;
		x+=lowbit(x);
	}
}
int sum(int x){
	int ans=0;
	while(x>0){
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	cin>>q;
	for(i=1;i<=q;i++){
		scanf("%d%d",&ask[i].l,&ask[i].r);
		ask[i].bh=i;
	}
	sort(ask+1,ask+1+q,cmp);
	for(i=1;i<=q;i++){
		while(j<=ask[i].r){
			k=a[j];
			if(m.count(k)){
				add(m[k],-1);
				add(j,1);
				m[k]=j;
			}
			else{
				add(j,1);
				m[k]=j;
			}
			j++;
		}
		ask[i].sum=sum(ask[i].r)-sum(ask[i].l-1);
	}
	sort(ask+1,ask+1+q,cmp2);
	for(i=1;i<=q;i++){
		printf("%d\n",ask[i].sum);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
