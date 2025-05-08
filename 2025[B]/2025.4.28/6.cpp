#include<bits/stdc++.h>
using namespace std;
int T,i,j,n,k,m,f[1000009],p[31][1000009],d,last,vis[31],r,now,FF;
string s,t;
signed main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	for(i=0;i<=n-1;i++)p[s[i]-'a'+1][++p[s[i]-'a'+1][0]]=i;
	f[n]=1;now=1;
	for(i=n-1;i>=0;i--){
		vis[(s[i]-'a'+1)]=1;FF=0;
		for(j=1;j<=k;j++){
			if(vis[j]==0)FF=1;
		}
		if(FF==0){
			now++;
			for(j=1;j<=k;j++)vis[j]=0;
		}
		f[i]=now;
	}
	cin>>T;
	while(T--){
		cin>>t;m=t.length();last=-1;
		for(i=0;i<=m-1;i++){
			d=lower_bound(p[t[i]-'a'+1]+1,p[t[i]-'a'+1]+1+p[t[i]-'a'+1][0],last+1)-(p[t[i]-'a'+1]);
			if(d>p[t[i]-'a'+1][0]){
				last=-2;
				break;
			}
			else last=p[t[i]-'a'+1][d];
		}
		if(last==-2){
			printf("0\n");
		}
		else{
			printf("%d\n",f[last+1]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
