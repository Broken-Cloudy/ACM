#include<bits/stdc++.h>
using namespace std;
struct nod{
	int bh,val;
}a[109],c[109];
int n,x,i,j,vis[109],b[109],anss[109],ANS=1e9+7;
bool cmp(nod x,nod y){
	return x.val<y.val;
}
void dfs(int x,int ans){
	int c[109],i;
	if(ans>=ANS)return;
	memcpy(c,b,sizeof(b));
	if(x==0&&ans<ANS){
		for(i=1;i<=n;i++){
			if(!vis[i])c[++c[0]]=a[i].bh;
		}
		memcpy(anss,c,sizeof(anss));
		ANS=ans;
		return;
	}
	for(i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			b[++b[0]]=a[i].bh;
			if(x>0){
				dfs(x-a[i].val,ans+a[i].val);
			}
			else{
				dfs(x+a[i].val,ans+a[i].val);
			}
			b[b[0]]=0;b[0]--;
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("7.in","r",stdin);freopen("7.out","w",stdout);
	cin>>n>>x;
	for(i=1;i<=n;i++)scanf("%d",&a[i].val),a[i].bh=i,c[i]=a[i];
	for(i=1;i<=n;i++){
		if(abs(x)==a[i].val){
			ANS=a[i].val;
			anss[++anss[0]]=a[i].bh;vis[a[i].bh]=1;
			for(j=1;j<=n;j++)if(!vis[j])anss[++anss[0]]=a[j].bh;
			cout<<ANS<<endl;
			for(i=1;i<=n;i++)cout<<anss[i]<<' ';
			return 0;
		}
	}
	dfs(x,0);
	cout<<ANS<<endl;
	for(i=1;i<=n;i++)cout<<anss[i]<<' ';
	fclose(stdin);fclose(stdout);
	return 0;
}
