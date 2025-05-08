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
void dfs(int deep,int start,int end){
	int i,t;
	for(i=1;i<=9;i++){
		if(a[i]!=0&&de[i][a[i]+1]!=0&&vis[de[i][a[i]+1]]==0&&de[i][a[i]+1]<=end)return;
		if(a[i]-1!=0&&de[i][a[i]-1]!=0&&vis[de[i][a[i]-1]]==0&&de[i][a[i]-1]>=start)return;
	}
	if(deep==len+1){
		ans=max(ans,end-start+1);
		return;
	}
	int num=jud(c[deep]);
	if(a[num]+1>de[num][0])return;
	else if(deep==1){
		for(i=1;i<=de[num][0];i++){
			a[num]=i;//第几个'P'
			vis[de[num][i]]=1;
			dfs(deep+1,de[num][i],de[num][i]);
			vis[de[num][i]]=0;
		}
	}
	else{
		i=a[num]+1;
		while(de[num][i]<end&&i<=de[num][0]){
			i++;
		}
		if(de[num][i]<=)
		t=a[num];
		a[num]=i;
		vis[de[num][i]]=1;
		dfs(deep+1,start,de[num][i]);
		vis[de[num][i]]=0;
		a[num]=t;
	}
}
int main(){
	freopen("4a.in","r",stdin);freopen("4a.out","w",stdout);
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
		dfs(1,0,0);
		cout<<ans<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
