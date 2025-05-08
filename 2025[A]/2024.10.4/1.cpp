#include<bits/stdc++.h>
#define int long long
using namespace std;
int Case,n,m,cnt,i,j,tow,ans;
char S[1000009],T[1000009];
struct Trie{
	int fail;//失配指针 
	int son[26];
	int end;//以此结点结尾的字符串 
}AC[1000009];
int num(char c){return (c-'a');}
void build(){//建Trie树 
	int i,tow=0;
	int len=strlen(S+1);
	for(i=1;i<=len;i++){
		if(!AC[tow].son[num(S[i])])AC[tow].son[num(S[i])]=++cnt;
		tow=AC[tow].son[num(S[i])];
	}
	AC[tow].end++;
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
			//新建标识v，只能用来判定，不能用来被赋值啊！！！！ 
			if(AC[u].son[i]){//四边形法则 
				AC[AC[u].son[i]].fail=AC[AC[u].fail].son[i];//爹的失配指针的儿子 
				Q.push(AC[u].son[i]);
			}
			else AC[u].son[i]=AC[AC[u].fail].son[i];//三角形法则 
		}
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>Case;
	while(Case--){
		scanf("%s",S+1);
		build();
	}
	build_fail();
	scanf("%s",T+1);
	int len=strlen(T+1);
	for(i=1;i<=len;i++){
		tow=AC[tow].son[num(T[i])];
		for(j=tow;j;j=AC[j].fail){
			if(AC[j].end>=0){
				ans+=AC[j].end;
				AC[j].end=-1;//已经统计出现过了 
			}
			else break;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
