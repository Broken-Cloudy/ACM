#include<bits/stdc++.h>
#define int long long
using namespace std;
int nian,yue,ri,tt,ans;
int check(int nian,int yue,int ri){
	int ans1=0,ans2=0;
	ans1+=(nian/1000%10);ans1+=(nian/100%10);
	ans1+=(nian/10%10);ans1+=(nian/1%10);
	ans2+=(yue/10%10);ans2+=(yue/1%10);
	ans2+=(ri/10%10);ans2+=(ri/1%10);
	if(ans1==ans2)return 1;
	else return 0;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	for(nian=1900;nian<=9999;nian++){
		for(yue=1;yue<=12;yue++){
			if(yue==1||yue==3||yue==5||yue==7||yue==8||yue==10||yue==12){
				tt=31;
			}
			else if(yue==4||yue==6||yue==9||yue==11)tt=30;
			else{
				if(nian%400==0)tt=29;
				else if(nian%4==0&&nian%100!=0){
					tt=29;
				}
				else tt=28;
			}
			for(ri=1;ri<=tt;ri++){
				ans+=check(nian,yue,ri);
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
