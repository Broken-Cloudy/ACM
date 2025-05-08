#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,trie[3000009][63],n,q,i,j,len,tow,cnt,qua[3000009];
string s;
int num(char c){
	if(c>='a'&&c<='z'){//0--25
		return (c-'a');
	}
	else if(c>='A'&&c<='Z'){//26--51
		return (c-'A'+26);
	}
	else return (c-'0'+52);//52--61
}
void dfs(int tow){
	int i;
	for(i=0;i<=62;i++){
		if(trie[tow][i]){
			dfs(trie[tow][i]);
			trie[tow][i]=0;
		}
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&q);
		while(n--){
			cin>>s;len=s.length();tow=0;//指针 
			for(j=0;j<len;j++){
				if(!trie[tow][num(s[j])]){
					cnt++;
					trie[tow][num(s[j])]=cnt;//记录位置 
					tow=cnt;
				}
				else tow=trie[tow][num(s[j])];
				qua[tow]++;
			}
		}
		while(q--){
			cin>>s;len=s.length();tow=0;
			for(j=0;j<len;j++){
				if(tow||j==0)tow=trie[tow][num(s[j])];
			}
			printf("%lld\n",qua[tow]);
		}
		//清空
		for(i=1;i<=cnt;i++)qua[i]=0;cnt=0;
		dfs(0);
	}
	fclose(stdin);fclose(stdout);
}
