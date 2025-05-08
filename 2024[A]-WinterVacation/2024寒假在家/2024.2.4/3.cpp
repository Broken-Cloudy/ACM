#include<bits/stdc++.h>
#define ll long long
using namespace std;
char chr,s[100009];
ll n,len,ans,i;
int main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n;getchar();chr=getchar();
	scanf("%s",s+1);len=strlen(s+1);
	for(i=1;i<=len;i++){
		if(s[i]==chr){
			ans+=min(i,len-i+1);
		}
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
