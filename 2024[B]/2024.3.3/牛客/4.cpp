#include<bits/stdc++.h>
using namespace std;
int n,a[100009],f[100009],i,change[100009],m[100009],ans,j;
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		if(a[i]<=n){
			if(m[a[i]]==0){
				m[a[i]]=1;
			}
		}
	}
	for(i=1;i<=n;i++){
		if(m[i]==0){
			ans++;
			change[ans]=i;
		}
	}
	cout<<ans<<endl;j=1;
	for(i=1;i<=n;i++){
		if(a[i]>n){
			printf("%d %d\n",i,change[j]);
			j++;
		}
		else if(m[a[i]]==1){
			m[a[i]]=0;
		}
		else{
			printf("%d %d\n",i,change[j]);
			j++;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
