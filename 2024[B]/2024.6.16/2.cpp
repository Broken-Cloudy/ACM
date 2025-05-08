#include<bits/stdc++.h>
using namespace std;
int num[1000009];
int n,k,i,zuo=1,you,t[1000009],j,ans[1000009];
struct nod1{
	int l,r;
};
nod1 a[1000009];
bool cmp(nod1 x,nod1 y){
	if(x.l==y.l)return x.r<y.r;
	else return x.l<y.l;
}
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=k;i++){
		scanf("%d%d",&a[i].l,&a[i].r);
	}
	sort(a+1,a+1+k,cmp);
	for(j=a[1].l;j<=a[1].r;j++){
		t[j]=1;
	}
	you=a[1].r;
	for(i=2;i<=k;i++){
		for(j=you+1;j<=a[i].r;j++){
			t[j]=i;//进场时间 
		}
		you=max(you,a[i].r); 
	}
	zuo=1;
	for(i=1;i<=k;i++){
		for(j=zuo;j<=a[i].l-1;j++){
			if(t[j]==0)ans[j]=0;//没有进场 
			else ans[j]=i-t[j];//离场时间 
		}
		zuo=max(zuo,a[i].l);
	}
	for(j=zuo;j<=n;j++){
		ans[j]=k-t[j];
	}
	sort(ans+1,ans+1+n);
	cout<<ans[n/2+1]<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
