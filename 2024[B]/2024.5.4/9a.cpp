#include<bits/stdc++.h>
using namespace std;
int cnt,n,m,i,j,ans;
string b[400009];
bool c[400009];
struct nod{
	string num;
	int same,right;
};
bool cmp(nod x,nod y){
	if(x.same==y.same)return (x.right+x.same)<(y.right+y.same);
	return x.same>y.same;
}
nod a[109];
void dfs(int x,string s){
	int vis[12],i;
	string s1=s;
	memset(vis,0,sizeof(vis));
	int len=s.length();
	for(i=0;i<len;i++){
		vis[s[i]-'0']=1;
	}
	for(i=0;i<=9;i++){
		if(vis[i]==0){
			s1[x]=(i+48);
			b[++cnt]=s1;
		}
	}
}
void dfss(int x,int y,string s){
	int vis[12],i,j;
	string s1=s;
	memset(vis,0,sizeof(vis));
	int len=s.length();
	for(i=0;i<len;i++){
		vis[s[i]-'0']=1;
	}
	for(i=0;i<=9;i++){
		for(j=0;j<=9;j++){
			if(vis[i]==0&&vis[j]==0){
				s1[x]=(i+48);
				s1[y]=(j+48);
				b[++cnt]=s1;
			}
		}
	}
}
void jud(string s,int same,int right){
	int i,Same,Right,j;
	int vis[19];
	memset(vis,0,sizeof(vis));
	for(i=0;i<m;i++)vis[s[i]-'0']=1;
		for(i=1;i<=cnt;i++){
			if(c[i]==1)continue;
			Same=0;Right=0;
			for(j=0;j<m;j++){
				if(b[i][j]==s[j])Same++;
				else if(vis[b[i][j]-'0']==1)Right++;
			}
			if(Same==same&&Right==right){
				continue;
			}
			else{
				ans--;c[i]=1;
			}
		}
	
}
int main(){
	freopen("9a.in","r",stdin);freopen("9a.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i].num>>a[i].same>>a[i].right;
	}
	sort(a+1,a+1+n,cmp);
	if(a[1].same==m-1){
		for(i=0;i<m;i++){
			dfs(i,a[1].num);
		}
		ans=cnt;
		for(i=2;i<=n;i++){
			jud(a[i].num,a[i].same,a[i].right);
			if(ans==1){
				for(i=1;i<=cnt;i++){
					if(c[i]==0)cout<<b[i];
				}
				break;
			}
		}
	}
	else if(a[1].same==m-2){
		for(i=0;i<m;i++){
			for(j=i;j<m;j++){
				if(i!=j)dfss(i,j,a[1].num);
			}
		}
		ans=cnt;
		for(i=2;i<=n;i++){
			jud(a[i].num,a[i].same,a[i].right);//b->c
			if(ans==1){
				for(i=1;i<=cnt;i++){
					if(c[i]==0)cout<<b[i];
				}
				break;
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
