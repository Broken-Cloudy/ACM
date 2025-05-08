#include<bits/stdc++.h>
using namespace std;
int n,ame[5777],i,a[4009],cnt1,cnt2,b[4009],ge1,ge2,j,km;
bool vis[4009];
bool flag=0;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n*2;i++){
		scanf("%d",&ame[i]);
	}
	bool f=1;
	a[++cnt1]=ame[1];vis[1]=1;km=1;
	for(i=1;i<=2*n;i++){
		if(vis[i]==1)continue;
		if(flag==1)break;
		if(cnt1==n){
			for(j=1;j<=2*n;j++){
				if(vis[j]==0){
					b[++cnt2]=ame[j];
				}
			}
			break;
		}
		else if(cnt2==n){
			for(j=1;j<=2*n;j++){
				if(vis[j]==0){
					a[++cnt1]=ame[j];
				}
			}
			break;
		}
		if(ame[i-1]==a[cnt1]){
			f=1;
		}
		else f=0;
		for(j=km;j<=n;j++){
			if(ame[j]>ame[i]&&vis[j]!=1){
				vis[j]=1;
				if(f==1)b[++cnt2]=ame[j];
				else a[++cnt1]=ame[j];
				break;
			}
		}
		if(j==n+1)flag=1;
	}
	if(flag=1)cout<<0<<endl;
	else{
		cout<<1<<endl;
		for(i=1;i<=cnt1;i++)cout<<a[i]<<' ';
		cout<<endl;
		for(i=1;i<=cnt2;i++)cout<<b[i]<<' ';
		cout<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
