#include<bits/stdc++.h>
using namespace std;
string ss,s[100009],rr;
int N,i,j,m;
map<string,map<int,int>>M;
signed main(){
	freopen("9.in","r",stdin);freopen("9.out","w",stdout);
	cin>>N;getchar();
	for(i=1;i<=N;i++){
		getline(cin,s[i]);
	}
	sort(s+1,s+1+N);
	for(i=1;i<=N;i++){
		int len=s[i].length();
		ss.clear();
		if(s[i][0]!=' ')ss+=s[i][0];
		for(j=1;j<len;j++){
			if(s[i][j-1]==' '&&s[i][j]!=' '){
				ss+=s[i][j];
			}
		}
		M[ss][++M[ss][0]]=i;
	}
	cin>>m;getchar();
	while(m--){
		getline(cin,rr);
		int ll=rr.length();
		ss.clear();
		if(rr[0]!=' ')ss+=rr[0];
		for(j=1;j<ll;j++){
			if(rr[j-1]==' '&&rr[j]!=' '){
				ss+=rr[j];
			}
		}
		if(M[ss][0]>0){
			for(j=1;j<=M[ss][0];j++){
				if(j==M[ss][0])cout<<s[M[ss][j]]<<'\n';
				else cout<<s[M[ss][j]]<<'|';
			}
		}
		else{
			cout<<rr<<endl;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
