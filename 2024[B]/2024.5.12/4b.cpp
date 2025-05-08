#include<bits/stdc++.h>
using namespace std;
//a[]表示调查到哪一个 
int de[18][10009],n,Q,i,len,a[18],ans,vis[10009];
char c1[10009],c[12];
int jud(char x){
	if(x=='P')return 1;
	else if(x=='Q')return 2;
	else if(x=='Y')return 3;
	else if(x=='S')return 4;
	else if(x=='Z')return 5;
	else if(x=='T')return 6;
	else if(x=='M')return 7;
	else if(x=='N')return 8;
	else return 9;
}
int check(int a[]){
	int start=9999999,end=-1,i;
	bool f=0;
	for(i=1;i<=9;i++){
		if(a[i]!=0)start=min(start,de[i][a[i]]);
		if(a[i]!=0)end=max(end,de[i][a[i]]);
	}
	for(i=1;i<=9;i++){
		if(a[i]!=0){
			if(de[i][a[i]+1]!=0&&de[i][a[i]+1]<=end)f=1;
			if(a[i]-1!=0&&de[i][a[i]-1]>=start)f=1;
		}
		if(a[i]!=0)end=max(end,de[i][a[i]]);
	}
	if(f==1)return 0;
	else return (end-start+1);
}
void dfs(int deep){
	int i;
	if(deep==len+1){
		ans=max(ans,check(a));
		return;
	}
	int num=jud(c[deep]);
	for(i=1;i<=de[num][0];i++){
		a[num]=i;
		dfs(deep+1);
	}
}
int main(){
//	freopen("4b.in","r",stdin);freopen("4b.out","w",stdout);
	cin>>n>>Q;getchar();
	for(i=1;i<=n;i++){
		c1[i]=getchar();
		de[jud(c1[i])][++de[jud(c1[i])][0]]=i;
	}
	for(i=1;i<=Q;i++){
		ans=0;
		memset(vis,0,sizeof(vis));
		memset(a,0,sizeof(a));
		scanf("%s",c+1);
		len=strlen(c+1);
		dfs(1);
		cout<<ans<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
