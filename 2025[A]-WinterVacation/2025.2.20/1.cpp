#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,A,B,AB,BA,j,ab[500009],ba[500009],cnt,SS;
char a[500009],ch,c[500009];
bool FF;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		n=ch=0;getchar();ch=getchar();FF=1;
		while(ch!='\n'&&ch!=-1&&ch!=' '){
			a[++n]=ch;ch=getchar();
		}
		SS=cnt=0;ab[0]=ba[0]=0;a[n+1]=a[n];
		scanf("%lld%lld%lld%lld",&A,&B,&AB,&BA);
		for(i=1;i<=n;i++){
			if(a[i]==a[i+1]){
				c[++cnt]=a[i];
				if(cnt%2==1){
					SS+=(cnt/2);
					if(c[1]=='A')A--;
					else B--;
				}
				else{
					if(c[1]=='A')ab[++ab[0]]=(cnt/2);
					else ba[++ba[0]]=(cnt/2);
				}
				cnt=0;
			}
			else{
				c[++cnt]=a[i];
			}
		}
		sort(ab+1,ab+1+ab[0]);sort(ba+1,ba+1+ba[0]);
		for(i=1;i<=ab[0];i++){
			if(AB>=ab[i])AB-=ab[i];
			else{
				SS+=(ab[i]-1);
				A--;B--;
			}
		}
		for(i=1;i<=ba[0];i++){
			if(BA>=ba[i])BA-=ba[i];
			else{
				SS+=(ba[i]-1);
				A--;B--;
			}
		}
		SS-=(AB+BA);
		if(SS>0){A-=SS;B-=SS;}
		if(A<0||B<0)FF=0;
		if(FF==1)printf("YES\n");
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
