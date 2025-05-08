#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,a[1000009],b[1000009],i,ans,SUM;
bool f=0;
struct nod{
	double x,y;
};
bool jud(int x,int y){
	if(x>=1&&x<=n&&y>=1&&y<=m)return 1;
	else return 0;
}
int dis(int x1,int y1,int x2,int y2){
	return (max(x1-x2,x2-x1)+max(y1-y2,y2-y1));
}
int manhate(int x,int y,int k){
	int ans=0;
	int i,j;
	for(i=x+k,j=y;i>=x&&j<=y+k;j++,i--){
		if(jud(i,j))ans++;
	}
	return ans;
}
signed main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>n>>m>>k;
	a[1]=manhate(1,1,k);
	b[1]=manhate(1,1,k);
	for(i=2;i<=m;i++){//第一行 
		if(1+k<=n){
			if(i+k<=m&&i-k<=1)a[i]=a[i-1]+1;
			else if(i+k>m&&i-k<=1)a[i]=a[i-1];
			else if(i+k>m&&i-k>1)a[i]=a[i-1]-1;
			else if(i+k<=m&&i-k>1)a[i]=a[i-1];
		}
		else{
			if(dis(n,1,1,i)==k)f=1;
			if(i+k<=m&&i-k<=1)a[i]=a[i-1]+1;
			else if(i+k>m&&i-k<=1)a[i]=a[i-1];
			else if(i+k>m&&i-k>1)a[i]=a[i-1]-1;
			else if(i+k<=m&&i-k>1)a[i]=a[i-1];
			if(f==0&&a[i]>0){
				a[i]--;
			}
		}
	}
	for(i=1;i<=m;i++)SUM+=a[i];
	f=0;
	for(i=2;i<=n;i++){//第一列  
		if(1+k<=m){
			if(i+k<=n&&i-k<=1)b[i]=b[i-1]+1;
			else if(i+k>n&&i-k<=1)b[i]=b[i-1];
			else if(i+k>n&&i-k>1)b[i]=b[i-1]-1;
			else if(i+k<=n&&i-k>1)b[i]=b[i-1];
		}
		else{
			if(dis(1,m,i,1)==k)f=1;
			if(i+k<=n&&i-k<=1)b[i]=b[i-1]+1;
			else if(i+k>n&&i-k<=1)b[i]=b[i-1];
			else if(i+k>n&&i-k>1)b[i]=b[i-1]-1;
			else if(i+k<=n&&i-k>1)b[i]=b[i-1];
			if(f==0&&b[i]>0){
				b[i]--;
			}
		}
	}
	for(i=1;i<=n;i++){
		ans+=SUM;
		SUM+=(b[i+1]-b[i])*m;
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
