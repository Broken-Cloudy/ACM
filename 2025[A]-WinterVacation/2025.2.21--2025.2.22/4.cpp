#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int x,y;
	int ans;
}t;
queue<nod>q;
int n,i,j,ans[109][109],VIS[259][109];
char c[109][109];
int check(int X,int Y){
	int i,j,ANS=-1,x,y,ans;
	while(!q.empty())q.pop();
	t.x=X;t.y=Y;t.ans=1;q.push(t);
	while(!q.empty()){
		t=q.front();q.pop();x=t.x;y=t.y;ans=t.ans;
		if(x==y)ANS=(ans-1)*2;
		if(ANS>-1||ans>n)break;
		for(i='a';i<='z';i++)VIS[i][0]=0;
		for(i=1;i<=n;i++){
			if(c[x][i]!='-'){
				if(i==y){
					ANS=(ans-1)*2+1;
					break;
				}
				VIS[c[x][i]][++VIS[c[x][i]][0]]=i;
			}
		}
		if(ANS>-1||ans>n)break;
		for(i=1;i<=n;i++){
			if(c[i][y]!='-'){
				for(j=1;j<=VIS[c[i][y]][0];j++){
					t.x=VIS[c[i][y]][j];t.y=i;t.ans=ans+1;
					q.push(t);
				}
			}
		}
	}
	return ANS;
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
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
			ans[i][j]=check(i,j);
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
