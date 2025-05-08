#include<bits/stdc++.h>
using namespace std;
int n,T,a[10009],i,ans,k,j,l;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		i=a[1];j=a[n];k=a[2];l=a[n-1];
		ans=max(i-j,j-i)+max(j-k,k-j)+max(k-l,l-k)+max(l-i,i-l);
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
