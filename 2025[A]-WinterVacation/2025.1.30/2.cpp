#include<bits/stdc++.h>
#define int long long
using namespace std;
int Time,len,ans0,ans1,ans,ANS,i,S0,S1,T0,T1;
deque<char>S,T;
char s[400009],t[400009];
bool FF;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>Time;
	while(Time--){
		scanf("%s",s+1);scanf("%s",t+1);FF=1;
		while(!S.empty())S.pop_back();
		while(!T.empty())T.pop_back();
		len=strlen(s+1);ANS=0;
		S0=S1=T0=T1=0;
		for(i=1;i<=len;i++){
			S.push_back(s[i]);
			if(s[i]=='1')S1++;
			else S0++;
			T.push_back(t[i]);
			if(t[i]=='1')T1++;
			else T0++;
		}
		if(S1!=T1||S0!=T0){
			printf("-1\n");
			continue;
		}
		while(!T.empty()){
			char t0=T.front(),t1;T.pop_front();
			int tn=1;
			while(!T.empty()){
				t1=T.front();
				if(t1!=t0){
					break;
				}
				else{
					tn++;
					T.pop_front();
				}
			}
			ans0=0;ans1=0;ans=0;
			while(!S.empty()){
				char s0=S.front(),s1;S.pop_front();
				int sn=1;ans++;
				while(!S.empty()){
					s1=S.front();
					if(s1!=s0){
						break;
					}
					else{
						sn++;
						S.pop_front();
					}
				}
				if(s0=='0')ans0+=sn;
				else ans1+=sn;
				if(t0=='0'){
					if(ans0==tn){
						while(ans1--)S.push_front('1');
						break;
					}
					else if(ans0>tn){
						FF=0;
						break;
					}
					else continue;
				}
				else{
					if(ans1==tn){
						while(ans0--)S.push_front('0');
						break;
					}
					else if(ans1>tn){
						FF=0;
						break;
					}
					else continue;
				}
			}
			ANS+=(ans/2);
		}
		if(FF==0)printf("-1\n");
		else{
			printf("%lld\n",ANS);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
