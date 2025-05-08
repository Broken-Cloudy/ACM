#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cnt,i,j,tow,ans,a[200009];
char T[2000009];
string S[200009];
struct Trie{
	int fail;//失配指针 
	int son[26];
	int end;//以此结点结尾的字符串 
}AC[200009];
int num(char c){return (c-'a');}
void build(int x){//建Trie树 
	int i,tow=0;
	int len=S[x].length();
	for(i=0;i<len;i++){
		if(!AC[tow].son[num(S[x][i])])AC[tow].son[num(S[x][i])]=++cnt;
		tow=AC[tow].son[num(S[x][i])];
	}
	AC[tow].end=x;
}
void build_fail(){
	int i;
	queue<int>Q;
	AC[0].fail=0;//结束标志 
	for(i=0;i<26;i++){//必须预处理，第二层指向根节点 
		if(AC[0].son[i]){
			AC[AC[0].son[i]].fail=0;//指向根节点
			Q.push(AC[0].son[i]);//压入队列 
		}
	}
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(i=0;i<26;i++){
			if(AC[u].son[i]){//四边形法则 
				AC[AC[u].son[i]].fail=AC[AC[u].fail].son[i];//爹的失配指针的儿子 
				Q.push(AC[u].son[i]);
			}
			else AC[u].son[i]=AC[AC[u].fail].son[i];//三角形法则 
		}
	}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	while(true){
		cin>>n;if(!n)break;
		for(i=1;i<=n;i++){
			cin>>S[i];
			build(i);
		}
		build_fail();
		scanf("%s",T+1);
		int len=strlen(T+1);tow=0;
		for(i=1;i<=len;i++){
			tow=AC[tow].son[num(T[i])];
			for(j=tow;j;j=AC[j].fail){
				a[AC[j].end]++;
			}
		}
		for(i=1;i<=n;i++){
			printf("%lld\n",a[i]);
		}
		break;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
