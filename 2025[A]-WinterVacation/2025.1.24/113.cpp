#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,i,ni,j;
struct nod{
	double val;
	int bh;
	int cnt;
}a[10009];
double pi,sum;
bool cmp(nod x,nod y){
	if(x.val==y.val&&x.cnt==y.cnt)return x.bh<y.bh;
	else if(x.val==y.val)return x.cnt>y.cnt;
	else return x.val>y.val;
}
signed main(){
	freopen("113.in","r",stdin);freopen("113.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&k);sum=0;
		for(j=1;j<=k;j++){
			scanf("%lld%lf",&ni,&pi);
			a[ni].val+=pi;sum+=pi;
			a[ni].cnt++;
		}
		a[i].val-=sum;a[i].bh=i;
	}
	for(i=1;i<=n;i++)a[i].val/=100.0;
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++)printf("%lld %.2lf\n",a[i].bh,a[i].val);
	fclose(stdin);fclose(stdout);
	return 0;
}
