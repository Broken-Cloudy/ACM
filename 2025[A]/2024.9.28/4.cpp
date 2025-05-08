#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,ans1,ans2,c1,c2,ans,cc;
char c[200009];
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n;getchar();
	for(i=1;i<=n;i++)c[i]=getchar();
	for(i=1;i<=n/2;i++){
		if(c[i]!='?')ans1+=(c[i]-'0');
		else c1++;
	}
	for(i=n/2+1;i<=n;i++){
		if(c[i]!='?')ans2+=(c[i]-'0');
		else c2++;
	}
	if(c1>=c2){//M first
		cc=c1-c2;
		if(ans1>ans2){
			cout<<"Monocarp"<<endl;
		}
		else{
			if((ans2-ans1)%9==0&&ans1+9*(cc/2)==ans2){
				cout<<"Bicarp"<<endl;
			}
			else cout<<"Monocarp"<<endl;
		}
	}
	else{
		cc=c2-c1;
		if(ans2>ans1){
			cout<<"Monocarp"<<endl;
		}
		else{
			if((ans1-ans2)%9==0&&ans2+9*(cc/2)==ans1){
				cout<<"Bicarp"<<endl;
			}
			else cout<<"Monocarp"<<endl;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
