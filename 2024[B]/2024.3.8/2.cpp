#include<bits/stdc++.h>
using namespace std;
int T,i,n,k,d,a[100009],v[100009],ans,j,c;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d%d%d",&n,&k,&d);
		ans=0;d--;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(i=0;i<k;i++){
			scanf("%d",&v[i]);
		}
		for(i=0;i<min(10009,d);i++){
			c=0;
			for(j=0;j<n;j++){
				if(a[j]-1==j){
					c++;
				}
			}
			ans=max(ans,c+(d-i)/2);
			for(j=0;j<v[i%k];j++){
				a[j]++;
			}
		}
		c=0;
		for(j=0;j<n;j++){
			if(a[j]-1==j){
				c++;
			}
		}
		ans=max(ans,c+(d-i)/2);
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
