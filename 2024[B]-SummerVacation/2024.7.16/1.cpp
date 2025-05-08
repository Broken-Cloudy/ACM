#include<bits/stdc++.h>
#define int long long
using namespace std;
char c[1009][1009],b[12];
int vis[1009][1009][6],d[4000009],cnt,ANS,vvis[1009][1009];
int f[1009][1009][6],n,m,i,q,u,v,j;
bool ff=0;
void getin(){
	getchar();
	char c=0;
	int i=0;
	while(c!='\n'&&c!=-1&&c!=' '){
		c=getchar();
		b[++i]=c;
	}
}
int check(char c){
	if(c=='a')return 1LL;//上 above
	else if(c=='b')return 2LL;//下 below
	else if(c=='l')return 3LL;//左 left
	else if(c=='r')return 4LL;//右 right
	else return 0LL;
}
int change(int type,char c){
	if(c=='|'){
		if(type==1||type==2)return type;
		else if(type==3)return 4;
		else return 3;
	}
	else if(c=='-'){
		if(type==3||type==4)return type;
		else if(type==1)return 2;
		else return 1;
	}
	else if(c=='/'){
		if(type==1)return 4;
		else if(type==2)return 3;
		else if(type==3)return 2;
		else return 1;
	}
	else{
		if(type==1)return 3;
		else if(type==2)return 4;
		else if(type==3)return 1;
		else return 2;
	}
}
//考虑出
int dfs(int x,int y,int type){//type照向下一束光 
	int ans=0;
	if(type==1){
		if(x-1>=1){
			if(c[x-1][y]=='|'){
				vis[x-1][y][change(type,c[x-1][y])]=1;
				d[++cnt]=(x-1)*1000000+y*100+change(type,c[x-1][y]);
				ans+=dfs(x-1,y,change(type,c[x-1][y]));
			}
			else if(vis[x-1][y][change(type,c[x-1][y])]==0){
				vis[x-1][y][change(type,c[x-1][y])]=1;
				d[++cnt]=(x-1)*1000000+y*100+change(type,c[x-1][y]);
				ans+=dfs(x-1,y,change(type,c[x-1][y]));
				if(vvis[x-1][y]==0)ans++;vvis[x-1][y]=1;
			}
		}
		else ff=1;
	}
	else if(type==2){
		if(x+1<=n){
			if(c[x+1][y]=='|'){
				vis[x+1][y][change(type,c[x+1][y])]=1;
				d[++cnt]=(x+1)*1000000+y*100+change(type,c[x+1][y]);
				ans+=dfs(x+1,y,change(type,c[x+1][y]));
			}
			else if(vis[x+1][y][change(type,c[x+1][y])]==0){
				vis[x+1][y][change(type,c[x+1][y])]=1;
				d[++cnt]=(x+1)*1000000+y*100+change(type,c[x+1][y]);
				ans+=dfs(x+1,y,change(type,c[x+1][y]));
				if(vvis[x+1][y]==0)ans++;vvis[x+1][y]=1;
			}
		}
		else ff=1;
	}
	else if(type==3){
		if(y-1>=1){
			if(c[x][y-1]=='-'){
				vis[x][y-1][change(type,c[x][y-1])]=1;
				d[++cnt]=x*1000000+(y-1)*100+change(type,c[x][y-1]);
				ans+=dfs(x,y-1,change(type,c[x][y-1]));
			}
			else if(vis[x][y-1][change(type,c[x][y-1])]==0){
				vis[x][y-1][change(type,c[x][y-1])]=1;
				d[++cnt]=x*1000000+(y-1)*100+change(type,c[x][y-1]);
				ans+=dfs(x,y-1,change(type,c[x][y-1]));
				if(vvis[x][y-1]==0)ans++;vvis[x][y-1]=1;
			}
		}
		else ff=1;
	}
	else{
		if(y+1<=m){
			if(c[x][y+1]=='-'){
				vis[x][y+1][change(type,c[x][y+1])]=1;
				d[++cnt]=x*1000000+(y+1)*100+change(type,c[x][y+1]);
				ans+=dfs(x,y+1,change(type,c[x][y+1]));
			}
			if(vis[x][y+1][change(type,c[x][y+1])]==0){
				vis[x][y+1][change(type,c[x][y+1])]=1;
				d[++cnt]=x*1000000+(y+1)*100+change(type,c[x][y+1]);
				ans+=dfs(x,y+1,change(type,c[x][y+1]));
				if(vvis[x][y+1]==0)ans++;vvis[x][y+1]=1;
			}
		}
		else ff=1;
	}
	f[x][y][type]=ans;
	return ans;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		getchar();
		for(j=1;j<=m;j++){
			c[i][j]=getchar();
		}
	}
	cin>>q;
	for(int o=1;o<=q;o++){
		scanf("%lld%lld",&u,&v);
		getin();cnt=0;ff=0;
		if(f[u][v][check(b[1])]>0){
			ANS=f[u][v][check(b[1])];
		}
		else ANS=dfs(u,v,check(b[1]));
		printf("%lld\n",ANS);
		if(ff==0){
			for(i=1;i<=cnt;i++){
				int xx=d[i]/1000000;
				int yy=d[i]%1000000/100;
				int zz=d[i]%100;
				d[i]=0;
				vis[xx][yy][zz]=0;
				vvis[xx][yy]=0;
				f[xx][yy][zz]=ANS;
			}
		}
		else{
			for(i=1;i<=cnt;i++){
				int xx=d[i]/1000000;
				int yy=d[i]%1000000/100;
				int zz=d[i]%100;
				d[i]=0;
				vis[xx][yy][zz]=0;
				vvis[xx][yy]=0;
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
