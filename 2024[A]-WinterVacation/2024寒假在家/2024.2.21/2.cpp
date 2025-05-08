#include<bits/stdc++.h>
using namespace std;
const long long inf=1e9+7;
char c[200009],s[200009];
long long f[200009][3],len,i,ans,cnt;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	scanf("%s",s+1);
	len=strlen(s+1);
	for(i=1;i<=len;i++){
		if(s[i]=='m'&&s[i+1]=='y'&&s[i+2]=='g'&&s[i+3]=='o'){
			c[++cnt]=s[i];c[++cnt]=s[i+1];
			c[++cnt]=s[i+2];c[++cnt]=s[i+3];
			s[i]='-';s[i+1]='-';s[i+2]='-';s[i+3]='-';
			i+=4;
		}
	}
	for(i=1;i<=len;i++){
		if(s[i]!='-'){
			c[++cnt]=s[i];
		}
	}
	for(i=4;i<=len;i++){
		f[i][0]=f[i-1][1]%inf;
		f[i][1]=(f[i-1][0]+f[i-1][1])%inf;
		if(c[i]=='o'&&c[i-1]=='g'&&c[i-2]=='y'&&c[i-3]=='m'){
			f[i][1]++;f[i][1]%=inf;
		}
	}
	ans=(f[len][0]+f[len][1])%inf;
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
