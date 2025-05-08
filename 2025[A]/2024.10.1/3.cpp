#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,kk,last,i,cnt,u,len;
char c,s[300009],T[300009];
int vis[300009],in[300009],Map[300009];
struct kkk{
    int son[26],fail,flag,ans;
    void clear(){memset(son,0,sizeof(son)),fail=flag=ans=0;}
}trie[300009];
queue<int>q;
string ss;
void insert(char cc,int num){
    int u=1;
    int v=cc-'a';
    if(!trie[u].son[v])trie[u].son[v]=++cnt;
    u=trie[u].son[v];
    if(!trie[u].flag)trie[u].flag=num;
    Map[num]=trie[u].flag;
}
void getFail(){
    for(int i=0;i<26;i++)trie[0].son[i]=1;
    q.push(1);
    while(!q.empty()){
        int u=q.front();q.pop();
        int Fail=trie[u].fail;
        for(int i=0;i<26;i++){
            int v=trie[u].son[i];
            if(!v){trie[u].son[i]=trie[Fail].son[i];continue;}
            trie[v].fail=trie[Fail].son[i];in[trie[v].fail]++;
            q.push(v);
        }
    }
}
void topu(){
    for(int i=1;i<=cnt;i++)
    if(in[i]==0)q.push(i);
    while(!q.empty()){
        int u=q.front();q.pop();vis[trie[u].flag]=trie[u].ans;
        int v=trie[u].fail;in[v]--;
        trie[v].ans+=trie[u].ans;
        if(in[v]==0)q.push(v);
    }
}
void query(char *s){
    int u=1,len=strlen(s);
    for(int i=0;i<len;i++)
    u=trie[u].son[s[i]-'a'],trie[u].ans++;
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n;u=1;cnt=1;
	for(i=1;i<=n;i++){
		cin>>ss;
		if(ss=="add"){
			getchar();c=getchar();
			c=((c-'a'+last)%26)+'a';
			len++;T[len]=c;
			//insert
			insert(c,len);
    		getFail();
			//query
			u=trie[u].son[T[len]-'a'];
			trie[u].ans++;
			topu();
		}
		else{
			scanf("%lld",&kk);
    		kk=(kk+last)%len;
    		last=vis[Map[kk]];
    		printf("%lld\n",last);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
