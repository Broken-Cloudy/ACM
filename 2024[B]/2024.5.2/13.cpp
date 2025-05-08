#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,ans,n,m,j;
vector<vector<int> >a;
void dfs(int n1,int n2,int m1,int m2){//n行m列 
	if(n2==n1&&m2==m1)return;
	int b[n2-n1+5],c[m2-m1+5],i,j;
	int ANS=-1,hang=-1,lie=-1;
	for(i=n1;i<=n2;i++){//n行
		b[i]=0;
		for(j=m1;j<=m2;j++){//m列 
			b[i]+=a[i][j];
		} 
	} 
	for(i=m1;i<=m2;i++){//m列 
		c[i]=0;
		for(j=n1;j<=n2;j++){//n行 
			c[i]+=a[j][i];
		} 
	} 
	int zuo,you,shang,xia;
	for(i=m1+1;i<=m2;i++){//切开列 
		zuo=0,you=0;
		for(j=m1;j<i;j++){
			zuo+=c[j];
		}
		for(j=i;j<=m2;j++){
			you+=c[j];
		}
		if(zuo*you>=ANS){
			ANS=zuo*you;
			lie=i;
		}
	}
	for(i=n1+1;i<=n2;i++){//切行 
		shang=0,xia=0;
		for(j=n1;j<i;j++){
			shang+=b[j];
		}
		for(j=i;j<=n2;j++){
			xia+=b[j];
		}
		if(shang*xia>=ANS){
			ANS=shang*xia;
			hang=i;
		}
	}
	if(hang!=-1){
		dfs(n1,hang-1,m1,m2);
		dfs(hang,n2,m1,m2);
	}
	else{
		dfs(n1,n2,m1,lie-1);
		dfs(n1,n2,lie,m2);
	}
	ans+=ANS;
}
signed main(){
	freopen("13.in","r",stdin);freopen("13.out","w",stdout);
	cin>>n>>m;
	a.resize(n+10);
	for(i=1;i<n+10;i++){
		a[i].resize(m+10);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	dfs(1,n,1,m);
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
