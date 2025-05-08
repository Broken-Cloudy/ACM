#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,anss,x,i,zhi[100009],j,p,ANS;
int flag[1000009],F[1000009],ans[1000009],vis[21];
void dfs(int x,int xi,int y,int z,int w,int depth){
	int i;
	if(x==z){
		if(x%2==1){
			ANS-=((n-1)/(w*y));
		}
		else{
			ANS+=((n-1)/(w*y));
		}
		return;
	}
	if(depth==xi)return;
	else{
		dfs(x,xi,y,z+1,w*zhi[depth],depth+1);
		dfs(x,xi,y,z,w,depth+1);
	}
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	flag[1]=1; 
	for(i=2;i<=1000000;i++){
		if(flag[i]==0){
			ans[++anss]=i;//记录下来 
			F[i]=anss;
			for(j=i;j<=1000000;j+=i){
		    	flag[j]=1;//一下子筛到底 
		    }
		}
	}
	cin>>n;x=n;
	for(i=2;i*i<=n;i++){
		if(F[i]==0)continue;
		if(x%i==0)zhi[++zhi[0]]=i;
		while(x%i==0){
			x/=i;
		}
	}
	ANS=n-1;
	if(x>1)zhi[++zhi[0]]=x;
	for(j=1;j<=zhi[0];j++){
		for(i=1;i<=j;i++){
			dfs(i,j,zhi[j],1,1,1);
		}
	}
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
