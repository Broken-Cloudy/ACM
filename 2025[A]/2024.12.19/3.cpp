#include<bits/stdc++.h>
#define int long long
using namespace std;
char c[5009];
int l1,l2,n,r1,r2,i,j,len,T,a[5009],anss[5009],ans[5009];
void com(int l,int r){
	bool FF=0;
	int i,j;
	memset(ans,0x3f,sizeof(ans));
	for(i=r,j=n;i>=l&&j>=1;i--,j--){
		ans[j]=a[i]^a[j];
	}
	for(i=1;i<=n;i++){
		if(ans[i]>=2)ans[i]=c[i]-'0';
	}
	for(i=1;i<=n;i++){
		if(ans[i]==anss[i])continue;
		else if(ans[i]>anss[i]){
			for(j=1;j<=n;j++)anss[j]=ans[j];
			l2=l;r2=r;
			return;
		}
		else return;
	}
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%s",c+1);
		n=strlen(c+1);
		l1=1;r1=n;l2=1;r2=1;
		for(i=1;i<=n;i++){
			if(c[i]=='0'){
				len=n-i+1;
				break;
			}
		}
		for(i=1;i<=n;i++)a[i]=c[i]-'0',anss[i]=a[i];
		for(i=1;i<=n-len+1;i++){
			j=i+len-1;
			com(i,j);
		}
		printf("%lld %lld %lld %lld\n",l1,r1,l2,r2);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
