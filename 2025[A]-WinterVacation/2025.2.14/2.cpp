#include<bits/stdc++.h>
#define int long long
using namespace std;
int N,k,i,j,a[100009],f[100009],p,b[100009],ss;
int find(int x){
	if(f[x]==x)return x;
	else{
		f[x]=find(f[x]);
		return f[x];
	}
}
map<int,map<int,int>>M;
map<int,map<int,int>>m;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>N>>k;
	if(N==1){
		printf("Yes\n");
		return 0;
	}
	for(i=1;i<=N;i++)scanf("%lld",&a[i]);
	//1
	for(i=1;i<=N;i++)f[i]=i;
	for(i=1;i<=N;i++){
		if(i-k>=1){
			if(find(i)!=find(i-k)){
				f[find(i)]=find(i-k);
			}
		}
	}
	for(i=1;i<=N;i++){
		m[find(i)][++m[find(i)][0]]=i;
	}
	for(i=1;i<=N;i++){
		if(m[i][0]>0){
			b[0]=0;
			for(j=1;j<=m[i][0];j++)b[++b[0]]=a[m[i][j]];
			sort(b+1,b+1+b[0]);
			for(j=1;j<=m[i][0];j++)a[m[i][j]]=b[j];
		}
	}
	//2
	for(i=1;i<=N;i++){
		M[a[i]][0]++;
		M[a[i]][M[a[i]][0]]=i;
	}
	for(i=1;i<=N;i++)f[i]=i;m.clear();
	for(i=1;i<=N;i++){
		for(j=1;j<=M[a[i]-k][0];j++){
			p=M[a[i]-k][j];
			if(find(p)!=find(i)){
				f[find(i)]=find(p);
			}
		}
	}
	for(i=1;i<=N;i++){
		m[find(i)][++m[find(i)][0]]=i;
	}
	for(i=1;i<=N;i++){
		if(m[i][0]>0){
			b[0]=0;
			for(j=1;j<=m[i][0];j++)b[++b[0]]=a[m[i][j]];
			sort(b+1,b+1+b[0]);
			for(j=1;j<=m[i][0];j++)a[m[i][j]]=b[j];
		}
	}
	for(i=1;i<=N;i++){
		if(a[i]<ss){
			printf("No\n");
			return 0;
		}
		else ss=max(ss,a[i]);
	}
	printf("Yes\n");
	fclose(stdin);fclose(stdout);
	return 0;
}
