#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cnt,i,j,tow,ans;
char T[1000009];
string S[1000009];
struct Trie{
	int fail;//失配指针 
	int son[26];
	int end;//以此结点结尾的字符串 
}AC[1000009];
struct nod{
	int bh,val;
}a[1000009];
bool cmp(nod x,nod y){
	if(x.val==y.val)return x.bh<y.bh;
	else return x.val>y.val;
}
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
			//新建标识v，只能用来判定，不能用来被赋值啊！！！！ 
			if(AC[u].son[i]){//四边形法则 
				AC[AC[u].son[i]].fail=AC[AC[u].fail].son[i];//爹的失配指针的儿子 
				Q.push(AC[u].son[i]);
			}
			else AC[u].son[i]=AC[AC[u].fail].son[i];//三角形法则 
		}
	}
}
void clear_Trie(){//清空树 
	queue<int>qq;cnt=0;
	int i,tow;qq.push(0);
	while(!qq.empty()){
		int t=qq.front();qq.pop();
		for(i=0;i<26;i++){
			if(AC[t].son[i]){
				qq.push(AC[t].son[i]);
				AC[t].son[i]=AC[t].end=AC[t].fail=0;
			}
		}
	}
	memset(a,0,sizeof(a));
}
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	while(true){
		cin>>n;if(!n)break;
		for(i=1;i<=n;i++){
			a[i].bh=i;
			cin>>S[i];
			build(i);
		}
		build_fail();
		scanf("%s",T+1);
		int len=strlen(T+1);tow=0;
		for(i=1;i<=len;i++){
			tow=AC[tow].son[num(T[i])];
			for(j=tow;j;j=AC[j].fail){
				a[AC[j].end].val++;
			}
		}
		sort(a+1,a+1+cnt,cmp);ans=a[1].val;
		printf("%lld\n",ans);
		for(i=1;i<=n;i++){
			if(ans==a[i].val)cout<<S[a[i].bh]<<endl;
			else break;
		}
		clear_Trie();
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
