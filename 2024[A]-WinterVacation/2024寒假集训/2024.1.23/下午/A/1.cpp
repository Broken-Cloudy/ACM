#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll n,q,i,op,ans,sum,k,x;
ll Z,NUM,maxz;
struct nod{
	ll num,z;
};
nod a[1000009];
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i].num);
		a[i].z=1;
		sum+=a[i].num;
	}
	for(int o=1;o<=q;o++){
		scanf("%lld",&op);
		if(op==1){
			scanf("%lld%lld",&x,&k);
			if(a[x].z>Z){
				sum+=(k-a[x].num);
				a[x].z++;//״̬++ 
				maxz=max(maxz,a[x].z);
				ans+=sum;
			}
			else{
				sum+=(k-NUM);
				a[x].z=Z+1;
				ans+=sum;
			}
		}
		else{
			scanf("%lld",&k);
			sum=n*k;
			Z=maxz+1;
			maxz=Z;
			NUM=k;
			ans+=sum;
		}
	}
	printf("%lld\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
