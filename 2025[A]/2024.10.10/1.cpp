#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=1e8-3;
struct nod{
	int bh,val;
}a[100009],d[100009];
int n,ans,b[100009],c[100009],i;
bool cmp(nod x,nod y){
	return x.val<y.val;
}
void S(int L,int R){
	if(L==R)return;
	int mid=(L+R)/2;
	S(L,mid);S(mid+1,R);
	int i=L,j=mid+1,k=L;
	while(i<=mid&&j<=R){
		if(b[i]<=b[j]){
			c[k]=b[i];
			k++;i++;
		}
		else{
			c[k]=b[j];
			k++;j++;
			ans+=(mid-i+1);
			ans%=P;
		}
	}
	while(i<=mid){
		c[k]=b[i];k++;i++;
	}
	while(j<=R){
		c[k]=b[j];k++;j++;
	}
	for(int w=L;w<=R;w++)b[w]=c[w];
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%lld",&a[i].val),a[i].bh=i;
	for(i=1;i<=n;i++)scanf("%lld",&d[i].val),d[i].bh=i;
	sort(a+1,a+1+n,cmp);sort(d+1,d+1+n,cmp);
	for(i=1;i<=n;i++){
		b[a[i].bh]=d[i].bh;
	}
	S(1,n);ans%=P;
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
