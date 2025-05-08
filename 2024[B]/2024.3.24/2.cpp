#include<bits/stdc++.h>
using namespace std;
char s[100009];
int a[100009],i,ans,sum;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(i=1;i<=len;i++){
		a[i]=s[i]-'0';
	}
	for(i=1;i<=len;i++){
		sum+=a[i];
		if(sum%9==0)ans++;
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
