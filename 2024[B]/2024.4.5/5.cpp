#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int b,bh;
}com[200009];
bool cmp(nod x,nod y){
	return x.b>y.b;
}
bool f[200009];
int n,q,a[200009],b[200009],sum[200009],Sum,i,wei,cnt,x;
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		Sum+=a[i];
	}
	for(i=1;i<=n;i++){
		scanf("%lld",&b[i]);
		com[i].bh=i;
		com[i].b=b[i];
		Sum+=b[i];
	}
	sort(com+1,com+1+n,cmp);
	sum[n]=Sum;cnt=1;wei=n;
	for(i=n-1;i>=1;i--){
		int y=(a[wei]+b[wei]);
		while(f[wei-1]==1){
			y+=a[wei-1];
			wei--;
		}
		if(com[cnt].b<=y){
			Sum-=y;
			wei--;
			sum[i]=Sum;
		}
		else{
			Sum-=(com[cnt].b);
			f[com[cnt].bh]=1;
			cnt++;
			sum[i]=Sum;
		}
		while(com[cnt].bh>wei){//ÓÐÐ§Ê± 
			cnt++;
		}
 	}
 	for(i=1;i<=q;i++){
 		scanf("%lld",&x);
 		printf("%lld\n",sum[x]);
	 }
	fclose(stdin);fclose(stdout);
	return 0;
}
