#include<bits/stdc++.h>
using namespace std;
struct nod{
	int w,v;
};
nod a[1009];
int i,j,n,m,f[100009],Sum,Ans,q,Gong;
map<int,int>Map;
int main(){
	freopen("9.in","r",stdin);freopen("9.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		scanf("%d%d",&a[i].w,&a[i].v);
	}
	for(i=1;i<=n;i++){
		Sum+=a[i].v;Gong+=a[i].w;
		for(j=Sum-a[i].v;j>=0;j--){
			if(f[j+a[i].v]==0){
				f[j+a[i].v]=f[j]+a[i].w;
			}
			else{
				f[j+a[i].v]=min(f[j]+a[i].w,f[j+a[i].v]);
			}
		}
		Ans=f[Sum];
		for(j=Sum-1;j>0;j--){
			if(f[j]==0||f[j]>=Ans){
				f[j]=Ans;
			}
			else{
				Ans=f[j];
			}
		}
	}
	for(i=1;i<=m;i++){
		scanf("%d",&q);
		if(q>=Gong)printf("%d\n",Sum);
		else{
			int d=upper_bound(f,f+Sum,q)-(f+1);
			printf("%d\n",d);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
