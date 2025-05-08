#include<bits/stdc++.h>
using namespace std;
int T,f[5009];
struct nod{
	int t,d,p;
};
nod a[5009];
int i,n,j,ans;
bool cmp(nod x,nod y){
	return x.d<y.d;
}
int main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		cin>>n;ans=0;
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].t,&a[i].d,&a[i].p);
		}
		sort(a+1,a+1+n,cmp);
		for(i=1;i<=n;i++){
			for(j=a[i].d;j>=a[i].t;j--){
				f[j]=max(f[j],f[j-a[i].t]+a[i].p);
			}
		}
		for(i=0;i<=5000;i++){
			ans=max(ans,f[i]);
		}
		cout<<ans<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
