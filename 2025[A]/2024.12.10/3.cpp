#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,ans,n2,n3;
string s;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>s;n2=n3=ans=0;
		int len=s.length();
		for(i=0;i<len;i++){
			ans+=s[i]-'0';
			if(s[i]=='2')n2++;
			if(s[i]=='3')n3++;
		}
		ans%=9;
		if(ans%2==0&&ans!=0){
			if(ans==2){
				if(n2>=5&&n3==1)printf("YES\n");
				else if(n2>=8&&n3==0)printf("YES\n");
				else if(n2>=2&&n3>=2)printf("YES\n");
				else printf("NO\n");				
			}
			else if(ans==4){
				if(n2>=4&&n3==1)printf("YES\n");
				else if(n2>=7&&n3==0)printf("YES\n");
				else if(n2>=1&&n3>=2)printf("YES\n");
				else printf("NO\n");				
			}
			else if(ans==6){
				if(n2>=3&&n3==1)printf("YES\n");
				else if(n2>=6&&n3==0)printf("YES\n");
				else if(n3>=2)printf("YES\n");
				else printf("NO\n");					
			}
			else{
				if(n2>=2&&n3>=1)printf("YES\n");
				else if(n2>=5&&n3==0)printf("YES\n");
				else printf("NO\n");				
			}
		}
		else{
			if(ans==0)printf("YES\n");
			else if(ans==1){
				if(n2>=1&&n3>=1)printf("YES\n");
				else if(n2>=4&&n3==0)printf("YES\n");
				else printf("NO\n");
			}
			else if(ans==3){
				if(n3>=1)printf("YES\n");
				else if(n2>=3&&n3==0)printf("YES\n");
				else printf("NO\n");				
			}
			else if(ans==5){
				if(n2>=2)printf("YES\n");
				else printf("NO\n");	
			}
			else{
				if(n2>=1)printf("YES\n");
				else printf("NO\n");				
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
