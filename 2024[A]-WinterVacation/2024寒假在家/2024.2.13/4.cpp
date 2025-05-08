#include<bits/stdc++.h>
using namespace std;
int T,n,a[200009],x,y,i;
long long ans;
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		map<int,map<int,int> >m;
		scanf("%d%d%d",&n,&x,&y);ans=0;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		for(i=n;i>=1;i--){
			int k1=a[i]%x;
			int k2=a[i]%y;
			int k3=(x-a[i]%x)%x;
			int k4=a[i]%y;
			ans+=m[k3][k4];
			m[k1][k2]++;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
