#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,j,ans[109][109];
char c[109][109],A[109];
int a[1009],b[1009],t,k,VIS[109];
int check(int x,int y){
	int i,j,ans=0,ANS=-1;
	a[0]=0;b[0]=0;
	queue<int>q1,q2;
	q1.push(x);q2.push(y);
	while(!q1.empty()&&!q2.empty()){
		if(ANS>0||ans>2*n)break;ans++;
		a[0]=0;A[0]=0;b[0]=0;
		for(i=1;i<=n;i++)VIS[i]=0;
		while(!q1.empty()){
			if(ANS>0)break;
			t=q1.front();q1.pop();
			for(i=1;i<=n;i++){
				if(c[t][i]!='-'){
					a[++a[0]]=i;
					A[++A[0]]=c[t][i];
					VIS[i]=c[t][i];
				}
			}
		}
		while(!q2.empty()){
			if(ANS>0)break;
			t=q2.front();q2.pop();
			for(i=1;i<=a[0];i++){
				if(VIS[a[i]]==c[i][t]){
					b[++b[0]]=i;
				}
			}
		}
		for(i=1;i<=a[0];i++)q1.push(a[i]);
		for(i=1;i<=b[0];i++)q2.push(b[i]);
	}
	return ANS;
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		getchar();
		for(j=1;j<=n;j++){
			c[i][j]=getchar();
			ans[i][j]=-1;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j)ans[i][j]=0;
			else if(c[i][j]!='-'){
				ans[i][j]=1;
			}
			else{
				ans[i][j]=check(i,j);
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(j==n)printf("%lld\n",ans[i][j]);
			else printf("%lld ",ans[i][j]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
