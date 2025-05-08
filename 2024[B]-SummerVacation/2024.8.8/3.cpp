#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,len,k,j,L1,L0,R1,R0,f[5009];
char a[5009],b[5009];
void getin(){
	int i;
	char c;
	c=getchar();
	while(c!='\n'&&c!=' '&&c!=-1){
		a[++len]=c;
		c=getchar();
	}
	for(i=1;i<=len;i++)b[i]=getchar();
	getchar();//¶ÁÈë»»ÐÐ 
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;getchar();
	while(T--){
		len=0;getin();f[0]=0;
		for(i=1;i<=len;i++){
			if(a[i]!=b[i]){
				f[i]=f[i-1]+1;
			}
			else f[i]=f[i-1];
		}
		for(i=1;i<=len;i++){
			if(a[i]==b[i]&&a[i]=='1'){
				for(j=1;j<i;j++){
					if(a[j]==b[j]&&a[j]=='1'){
						f[i]=min(f[i],f[j]);
					}
				}
				f[i]=min(f[i-1],f[i]);
			}
			else if(a[i]==b[i]&&a[i]=='0'){
				for(j=1;j<i;j++){
					if(a[j]==b[j]&&a[j]=='0'){
						f[i]=min(f[i],f[j]);
					}
				}
				f[i]=min(f[i-1],f[i]);
			}
			else{
				f[i]=min(f[i-1]+1,f[i]);
			}
		}
		if(f[len]==0){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
