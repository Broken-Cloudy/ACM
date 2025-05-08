#include<bits/stdc++.h>
using namespace std;
const int N=2200009,M=29;
struct nod{
	int charm,bh;
	int work[M];
};
nod a[N];
bool cmp(nod x,nod y){
	return x.charm>y.charm;
}
int vis[N],f[N],n,K,i,j,k,h,d,zhan[N],r,q;
int getnum(int x,int k,int num){
	int ans=0;
	for(int i=1;i<=k;i++){
		if((1<<(i-1))&x){
			ans+=(1<<(a[num].work[i]-1));
		}
	}
	return ans;
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>K;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i].charm);
		scanf("%d",&a[i].work[0]);
		a[i].bh=1;
		for(j=1;j<=a[i].work[0];j++){
			scanf("%d",&a[i].work[j]);
		}
	}
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++){
		h=1;d=0;zhan[++d]=0;
		k=a[i].work[0];
		while(h<=d){
			int t=zhan[h];
			for(j=1;j<=k;j++){
				int shiji=getnum(t|(1<<(j-1)),k,i);
				if((t&(1<<(j-1)))==0&&vis[shiji]==0){
					vis[shiji]=1;
					f[shiji]=a[i].bh;
					zhan[++d]=t|(1<<(j-1));
				}
			}
			h++;
		}
	}
	cin>>q;
	for(i=1;i<=q;i++){
		int ans=0;
		scanf("%d",&k);
		for(j=1;j<=k;j++){
			scanf("%d",r);
			ans+=(1<<(r-1));
		}
		if(f[ans]==0){
			printf("OMG!");
		}
		else{
			printf("%d\n",f[ans]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
