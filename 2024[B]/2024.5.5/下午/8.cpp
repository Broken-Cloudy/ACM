#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,W,i,a[200009],Sum,f[200009];
void dfs(int l,int r){
	int i;
	if(l==r){
		cout<<l<<endl;
		return;
	}
	else if(l==r-1){
		int ANS=0;
		memset(f,0,sizeof(f));
		int mid=r;
		for(i=1;i<=n;i++){
			f[i]=max(f[i],ANS);//不选
			if(i-mid>=0&&i+mid<=n+1)f[i]=max(f[i],f[i-mid]+a[i]); 
			ANS=max(ANS,f[i]);
		}
		if(ANS>=W){
			cout<<r<<endl;
			return;
		}
		else{
			cout<<l<<endl;
			return;
		}
	}
	else{
		int mid=(l+r)/2;
		int ANS=0;
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++){
			f[i]=max(f[i],ANS);//不选
			if(i-mid>=0&&i+mid<=n+1)f[i]=max(f[i],f[i-mid]+a[i]); 
			ANS=max(ANS,f[i]);
		}
		if(ANS>=W){
			dfs(mid,r);
		}
		else{
			dfs(l,mid);
		}
	}
}
signed main(){
	freopen("8.in","r",stdin);freopen("8.out","w",stdout);
	cin>>n>>W;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		Sum+=a[i];
	}
	if(Sum<W){
		cout<<"-1"<<endl;
	}
	else if(W==0){
		cout<<n+1<<endl;
	}
	else{
		dfs(1,n+1);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
