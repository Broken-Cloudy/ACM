#include<bits/stdc++.h>
using namespace std;
int n,i,a[200009],b[200009],j,ans;
void dfs(int x,int q,int deep){
	if(x*q>200000){
		ans=max(ans,deep);
		return;
	}
	if(b[x*q]>0){
		dfs(x*q,q,deep+1);
	}
	else{
		ans=max(ans,deep);
		return;
	}
}
int main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%d",&a[i]),b[a[i]]++;
	for(i=1;i<=200000;i++)ans=max(ans,b[i]);
	for(i=1;i<=200000;i++){
		if(b[i]>0){
			for(j=2;j<=450;j++){
				dfs(i,j,1);
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
