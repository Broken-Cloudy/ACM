#include<bits/stdc++.h>
using namespace std;
int T,n,i,a[200009],d[200009],tou,wei,ans;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d",&n);ans=1;tou=wei=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		d[++wei]=a[1];tou=1;
		for(i=1;i<=n;i++){
			if(a[i]==d[wei])continue;
			while(d[tou]+n-1<a[i]){
				d[tou]=0,tou++;
				if(tou==wei+1)break;
			}
			d[++wei]=a[i];
			ans=max(ans,wei-tou+1);
		}
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
