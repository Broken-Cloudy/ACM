#include<bits/stdc++.h>
using namespace std;
struct nod{
	int bh,num;
};
nod a[19],c[19];
int n,m,i,T,b[19],vs1[19],vs2[19],ans;
bool cmp(nod x,nod y){
	return x.num>y.num;
}
void dfs(int deep){
	if(deep==m+1){
		int i,k;
		for(i=1;i<=n;i++){
			c[i].num=a[i].num;
			c[i].bh=i;
		}
		for(i=1;i<=m;i++){
			if(b[i]==1){//failed
				c[vs1[i]].num+=3;
			}
			else if(b[i]==2){//draw
				c[vs1[i]].num++;
				c[vs2[i]].num++;
			}
			else{//win
				c[vs2[i]].num+=3;
			}
		}
		sort(c+1,c+1+n,cmp);
		k=1;
		for(i=1;i<=n;i++){
			if(i!=1&&c[i-1].num!=c[i].num)k=i;
			if(c[i].bh==1){
				ans=min(ans,k);
				break;
			}
		}
		return;
	}
	b[deep]=1;
	dfs(deep+1);
	b[deep]=2;
	dfs(deep+1);
	b[deep]=3;
	dfs(deep+1);
}
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d%d",&n,&m);
		ans=100;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i].num);
			a[i].bh=i;
		}
		for(i=1;i<=m;i++){
			scanf("%d%d",&vs1[i],&vs2[i]);
		}
		dfs(1);
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
