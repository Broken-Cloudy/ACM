#include<bits/stdc++.h>
#define int long long
using namespace std;
int N,G,K,i,SUM,nowkk;
struct nod{
	int val;
	string s;
}a[10009];
bool cmp(nod x,nod y){
	if(x.val==y.val)return x.s<y.s;
	else return x.val>y.val;
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>N>>G>>K;
	for(i=1;i<=N;i++){
		cin>>a[i].s;
		scanf("%lld",&a[i].val);
	}
	sort(a+1,a+1+N,cmp);
	for(i=1;i<=N;i++){
		if(a[i].val>=60){
			if(a[i].val>=G){
				SUM+=50;
			}
			else SUM+=20;
		}
	}
	cout<<SUM<<endl;nowkk=1;
	printf("%lld ",nowkk);cout<<a[1].s;printf(" %lld\n",a[1].val);
	for(i=2;i<=N;i++){
		if(a[i].val!=a[i-1].val){
			nowkk=i;
		}
		if(nowkk>K)break;
		printf("%lld ",nowkk);cout<<a[i].s;printf(" %lld\n",a[i].val);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
