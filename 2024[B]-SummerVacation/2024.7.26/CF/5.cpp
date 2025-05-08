#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int T,len,i,ans,cc,k,sum[200009];
int m[600009];
char c[200009],kk;
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>T;getchar();
	for(int o=1;o<=T;o++){
		len=0;kk=getchar();
		while(kk!='\n'&&kk!=-1&&kk!=' '){
			c[++len]=kk;
			kk=getchar();
		}
		for(i=0;i<=len;i++)sum[i]=0,m[i]=0;
		cc=300000;ans=0;k=0;m[0]=1;
		for(i=1;i<=len;i++){
			if(c[i]=='1'){
				cc++;
				m[cc]=m[cc-1]+1;
			}
			else{
				cc--;
				m[cc]=m[cc+1]+1;
			}
			sum[i]=sum[i-1]+m[cc];
			sum[i]%=mod;
		}
		printf("%lld\n",sum[len]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
