#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,A,B,AB,BA,vis[200009];
char a[200009],ch,now;
bool FF;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		n=ch=0;getchar();ch=getchar();
		while(ch!='\n'&&ch!=-1&&ch!=' '){
			a[++n]=ch;ch=getchar();
		}
		a[n+1]=a[n];i=1;
		for(i=1;i<=n;i++)vis[i]=0;
		scanf("%lld%lld%lld%lld",&A,&B,&AB,&BA);
		for(i=1;i<=n;i++){
			if(vis[i]==1)continue;
			if(a[i]=='B'&&a[i+1]=='B'&&a[i+2]=='A'){
				vis[i+1]=vis[i+2]=1;
			}
			if(a[i]=='A'&&a[i+1]=='B'&&a[i+2]=='B'){
				vis[i+1]=vis[i+2]=1;
			}
		}
		while(i<=n){
			if(vis[i]==1)continue;
			if(a[i+1]!=a[i]){
				now=a[i];
				if(now=='A'){
					if(AB==0){
						A--;i++;
					}
					else{
						AB--;i+=2;
					}
				}
				else{
					if(BA==0){
						B--;i++;
					}
					else{
						BA--;i+=2;
					}
				}
			}
			else{
				if(a[i]=='A')A--;
				else B--;
				i++;
			}
		}
		if(A<0||B<0){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
