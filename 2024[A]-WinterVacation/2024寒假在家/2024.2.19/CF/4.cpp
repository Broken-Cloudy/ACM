#include<bits/stdc++.h>
using namespace std;
const int inf=2147483647;
int a[200009],n,T,i,ans;
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d",&n);ans=0;
		map<int,int>m;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=1;i<=n;i++){
			if(m[a[i]]>=1){
				m[a[i]]--;
			}
			else{
				int k=a[i]^inf;
				ans++;
				m[k]++;
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
