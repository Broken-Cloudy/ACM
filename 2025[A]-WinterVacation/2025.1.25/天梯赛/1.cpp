#include<bits/stdc++.h>
#define int long long
using namespace std;
int N,i,j,k,cnt,ANS;
char c,ans[50009];
string s[109],ss[12];
void add(){
	cnt++;ans[cnt]='<';cnt++;ans[cnt]='c';
	cnt++;ans[cnt]='e';cnt++;ans[cnt]='n';
	cnt++;ans[cnt]='s';cnt++;ans[cnt]='o';
	cnt++;ans[cnt]='r';cnt++;ans[cnt]='e';
	cnt++;ans[cnt]='d';cnt++;ans[cnt]='>';
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>N;
	for(i=1;i<=N;i++){
		cin>>s[i];
	}
	cin>>k;getchar();
	while(c!=-1&&c!='\n'){
		c=getchar();cnt++;
		ans[cnt]=c;
		for(j=1;j<=10;j++)ss[j].clear();
		for(j=1;j<=10;j++){
			if(cnt-j+1<1)break;
			for(i=cnt-j+1;i<=cnt;i++){
				ss[j]+=ans[i];
			}	
		}
		for(j=10;j>=1;j--){
			if(ss[j]!=""){
				bool FF=0;
				for(i=1;i<=N;i++){
					if(ss[j]==s[i]){
						cnt-=j;add();
						ANS++;FF=1;
						break;
					}
				}
				if(FF==1)break;
			}
		}
	}
	if(ANS>=k){
		printf("%lld\n",ANS);
		printf("He Xie Ni Quan Jia!\n");
	}
	else{
		for(i=1;i<=cnt;i++)putchar(ans[i]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
