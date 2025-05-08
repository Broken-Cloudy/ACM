#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,i,j,k,sum,ans;
int A,B,C,D,acnt,bcnt,ccnt,dcnt,cha;
struct nod{
	int num,cnt;
};
nod a[200009];
bool cmp(nod x,nod y){
	return x.num<y.num;
}
signed main(){
	freopen("2extra.in","r",stdin);freopen("2extra.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i].num);
		}
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i].cnt);
		}
		for(i=1;i<n;i++){
			if(a[i].cnt*a[i].num>m){
				A=m/a[i].num*a[i].num;
				acnt=a[i].cnt-m/a[i].num;
				if(acnt==0){
					ans=max(A,ans);
					continue;
				}
				else{
					B=A+a[i].num;
					bcnt=m/a[i].num+1;//used
				}
			}
			else if(a[i].cnt*a[i].num==m){
				ans=m;
				break;
			}
			else{
				A=a[i].cnt*a[i].num;
			}
			ans=max(ans,A);
			if(a[i].num==a[i+1].num-1){
				cha=B-m;
				//if(cha==)
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
