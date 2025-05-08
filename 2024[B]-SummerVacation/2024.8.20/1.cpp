#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int a,b;
};
nod a[200009];
int T,n,k,i,ans,maxx,ANS;
bool cmp1(nod x,nod y){
	if(x.b==y.b)return x.a>y.a;
	else return x.b>y.b;
}
bool cmp2(nod x,nod y){
	return x.a<y.a;
}
bool check(int x,int k){//O(N)--O(NlogN)
	int i,cnt=0;
	int aq=(n+1)/2;//应该达到的中位数标准 
	for(i=n-1;i>=1;i--){
		if(a[i].a>=x){
			cnt++;
		}
		else{
			if(a[i].b==1&&(x-a[i].a)<=k){
				k-=(x-a[i].a);
				cnt++;
			}
		}
	}
	if(cnt>=aq){
		return true;
	}
	else return false;
}
void Find(int L,int R,int k){
	if(L==R){
		ANS=L;
	}
	else if(L+1==R){
		if(check(R,k)){
			ANS=R;
		}
		else{
			ANS=L;
		}
	}
	else{
		int mid=(L+R)/2;
		if(check(mid,k)){
			Find(mid,R,k);
		}
		else{
			Find(L,mid,k);
		}
		return;
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);maxx=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i].a),maxx=max(maxx,a[i].a);
		for(i=1;i<=n;i++)scanf("%lld",&a[i].b);
		sort(a+1,a+1+n,cmp1);
		if(a[1].b==1){
			a[1].a+=k;
			sort(a+1,a+1+n,cmp2);
			ans=a[n/2].a+a[n].a;
			//还原
			sort(a+1,a+1+n,cmp1); 
			a[1].a-=k;
			sort(a+1,a+1+n,cmp2);
			Find(1,maxx,k);
			ans=max(ans,ANS+a[n].a);
		}
		else{
			sort(a+1,a+1+n,cmp2);
			ans=a[n/2].a+a[n].a;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
