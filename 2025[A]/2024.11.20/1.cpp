#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,x,t[9],ans,SUM,TT,tt;
struct nod{
	int val,bh;
}a[9];
char ch;
void add(char cc){
	if(cc=='D')a[1].val++;
	if(cc=='C')a[2].val++;
	if(cc=='H')a[3].val++;
	if(cc=='S')a[4].val++;
}
bool cmp(nod x,nod y){
	return x.val>y.val;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);memset(t,0,sizeof(t));
		SUM=ans=0;
		for(i=1;i<=4;i++){
			a[i].bh=i;a[i].val=0;
		}
		for(i=1;i<=n;i++){
			getchar();
			ch=getchar();ch=getchar();
			add(ch);
		}
		for(i=1;i<=6;i++){
			scanf("%lld",&t[i]);
		}
		TT=t[5]+t[6];
		for(i=1;i<=4;i++){
			ans+=a[i].val/5;
			a[i].val%=5;
			SUM+=a[i].val;
		}
		sort(a+1,a+5,cmp);
		for(i=1;i<=4;i++){
			ans+=min(SUM/5,(3*t[a[i].bh]+a[i].val+TT)/5);tt=TT;
			if(min(SUM/5,(3*t[a[i].bh]+a[i].val+TT)/5)*5>3*t[a[i].bh]+a[i].val){
				TT-=min(SUM/5,(3*t[a[i].bh]+a[i].val+TT)/5)*5-(3*t[a[i].bh]+a[i].val);
			}
			SUM-=min(SUM/5,(3*t[a[i].bh]+a[i].val+tt)/5)*5;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
