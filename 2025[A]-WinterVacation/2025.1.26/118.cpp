#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,N,a[100009],p[100009],d;
signed main(){
	freopen("118.in","r",stdin);freopen("118.out","w",stdout);
	cin>>N;
	for(i=1;i<=N;i++)scanf("%lld",&a[i]);
	p[0]=1;p[p[0]]=a[1];
	for(i=2;i<=N;i++){
		p[p[0]+1]=999999LL;
		d=lower_bound(p+1,p+p[0]+1,a[i])-p;
		if(p[0]+1==d){
			p[0]++;
			p[p[0]]=a[i];
		}
		else{
			p[d]=a[i];
		}
	}
	printf("%lld\n",p[0]);
	fclose(stdin);fclose(stdout);
	return 0;
}
