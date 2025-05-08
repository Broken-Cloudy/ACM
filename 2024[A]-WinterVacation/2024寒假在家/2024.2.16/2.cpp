#include<bits/stdc++.h>
using namespace std;
int T,i,n,a[200009],mini,maxx;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d",&n);
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		mini=1e9+7;maxx=-1e9-7;
		for(i=2;i<=n;i++){
			mini=min(mini,a[i]);
		}
		for(i=1;i<n;i++){
			maxx=max(maxx,a[i]);
		}
		if(a[1]<=mini||a[n]>=maxx){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
