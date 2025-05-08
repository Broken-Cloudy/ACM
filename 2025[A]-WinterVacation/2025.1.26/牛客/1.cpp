#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,trie[1000009][63],n,m,q,i,j,len,tow,cnt,l,r,ans,maxx;
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
			ans++;
		}
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>m;
	while(n--){
		cin>>s;len=s.length();tow=0;//÷∏’Î 
		maxx=max(maxx,len);
		for(j=0;j<len;j++){
			if(!trie[tow][num(s[j])]){
				cnt++;
				trie[tow][num(s[j])]=cnt;//º«¬ºŒª÷√ 
				tow=cnt;
			}
			else tow=trie[tow][num(s[j])];
		}
	}
	cin>>l>>r;
	dfs(0);
	ans=ans*2-maxx;
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
