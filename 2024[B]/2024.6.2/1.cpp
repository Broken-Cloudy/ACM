#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,n,b,a[1009],ans,j,B,ANS;
struct nod{
	int s,p;
};
nod k[1009];
bool cmp(int x,int y){
	return x<y;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>B;
	for(i=1;i<=n;i++){
		scanf("%lld%lld",&k[i].s,&k[i].p);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j){
				a[j]=(k[j].s/2)+k[j].p;
			}
			else{
				a[j]=k[j].s+k[j].p;
			}
		}
		sort(a+1,a+1+n,cmp);
		b=B;
		ans=0;
		for(j=1;j<=n;j++){
			b-=a[j];
			if(b>=0){
				ans++;
			}
			else{
				break;
			}
		}
		ANS=max(ans,ANS);
	}
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
