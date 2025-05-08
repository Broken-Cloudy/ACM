#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int num,mag;
}a[1009];
bool cmp(nod x,nod y){
	return x.mag>y.mag;
}
int n,i,k[109],ANS;
bool F;
void insert(int x){
	int i;
	for(i=60;i>=0;i--){
		if(x&(1LL<<i)){
			if(k[i]){
				x^=k[i];
			}
			else{
				F=1;
				k[i]=x;
				break;
			}
		}
	}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].num,&a[i].mag);
	}
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;i++){
		F=0;
		insert(a[i].num);
		if(F==1)ANS+=a[i].mag;
	}
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
