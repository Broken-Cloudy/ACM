#include<bits/stdc++.h>
using namespace std;
int T,n,m,i,x,y,q;
string s[100010],S;
int main(){
	freopen("8.in","r",stdin);freopen("8.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		cin>>n>>m;
		for(i=1;i<=n;i++){
			cin>>s[i];
		}
		cin>>q;
		for(i=1;i<=q;i++){
			scanf("%d%d",&x,&y);
			S=s[x]+s[x];
			if(S.find(s[y])!=-1)printf("Yes\n");
			else printf("No\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
