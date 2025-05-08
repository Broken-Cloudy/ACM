#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,i,f[1009][2009][3],vis[1009][2009][3],cnt;
//1是int 2是double 3是pair 
map<string,int>m;
string s;
int dfs(int i){
	char c;
	int ans,depth=cnt;
	c=getchar();
	if(c=='p'){//p
		getchar();getchar();getchar();getchar();//air<
		cnt++;vis[i][depth][1]=cnt;f[i][cnt][1]=dfs(i);
		getchar();//,
		cnt++;vis[i][depth][2]=cnt;f[i][cnt][2]=dfs(i);
		getchar();//>
		ans=3;
	}
	else if(c=='i'){
		getchar();getchar();//nt
		ans=1;
	}
	else{//ouble
		getchar();getchar();getchar();getchar();getchar();
		ans=2;
	}
	if(depth==1){
		getchar();//空格
		s.clear();c=0;
		while(true){
			c=getchar();
			if(c==';')break;
			else s+=c;
		}
		m[s]=i;
	}
	return ans;
}
void DFS(int i,int depth,int type,int flag){//flag==1继续输入 
	char c;
	if(flag==1){
		c=getchar();
		if(c=='f'){
			getchar();getchar();getchar();getchar();
			c=getchar();
			if(c=='.')DFS(i,vis[i][depth][1],1,1);
			else DFS(i,vis[i][depth][1],1,0);
		}
		else{
			getchar();getchar();getchar();getchar();getchar();
			c=getchar();
			if(c=='.')DFS(i,vis[i][depth][2],2,1);
			else DFS(i,vis[i][depth][2],2,0);
		}
	}
	else{
		if(f[i][depth][type]==3){
			printf("pair<");
			DFS(i,vis[i][depth][1],1,0);
			printf(",");
			DFS(i,vis[i][depth][2],2,0);
			printf(">");
		}
		else if(f[i][depth][type]==2){
			printf("double");
		}
		else{
			printf("int");
		}
	}
}
void work(){
	string ss;ss.clear();
	char c;bool f=0;
	while(true){
		c=getchar();
		if(c==' '||c==-1||c=='\n')break;
		else if(c=='.'){
			f=1;break;
		}
		else ss+=c;
	}
	if(f==1)DFS(m[ss],1,1,1);
	else DFS(m[ss],1,1,0);
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++){
		getchar();//读入换行 
		cnt=1;
		f[i][1][1]=dfs(i);
	}
	getchar();//读入换行 
	while(q--){
		work();
		putchar('\n');
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
