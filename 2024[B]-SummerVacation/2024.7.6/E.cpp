#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c,ans;
signed main(){
	freopen("E.in","r",stdin);freopen("E.out","w",stdout);
	cin>>a>>b>>c;
	if(a%3==0&&a!=0){
		ans+=a/3;
		a-=a/3*3;
		ans--;
		a+=3;
	}
	else{
		ans+=a/3;
		a-=a/3*3;
	}
	if(b%3==0&&b!=0){
		ans+=b/3;
		b-=b/3*3;
		ans--;
		b+=3;
	}
	else{
		ans+=b/3;
		b-=b/3*3;
	}
	if(c%3==0&&c!=0){
		ans+=c/3;
		c-=c/3*3;
		ans--;
		c+=3;
	}
	else{
		ans+=c/3;
		c-=c/3*3;
	}
	if(a==1&&b==1&&c==1)ans++;
	else if(a==1&&b==2&&c==1)ans++;
	else if(a==1&&b==1&&c==2)ans++;
	else if(a==2&&b==1&&c==1)ans++;
	else if(a==2&&b==2&&c==1)ans++;
	else if(a==2&&b==1&&c==2)ans++;
	else if(a==1&&b==2&&c==2)ans++;
	else if(a==3&&b==1&&c==1)ans++;
	else if(a==1&&b==3&&c==1)ans++;
	else if(a==1&&b==1&&c==3)ans++;
	else if(a==3&&b==2&&c==1)ans++;
	else if(a==3&&b==1&&c==2)ans++;
	else if(a==2&&b==3&&c==1)ans++;
	else if(a==1&&b==3&&c==2)ans++;
	else if(a==1&&b==2&&c==3)ans++;
	else if(a==2&&b==1&&c==3)ans++;
	else if(a==2&&b==2&&c==2)ans+=2;
	else if(a==2&&b==2&&c==3)ans+=2;
	else if(a==3&&b==2&&c==2)ans+=2;
	else if(a==2&&b==3&&c==2)ans+=2;
	else if(a==1&&b==3&&c==3)ans+=2;
	else if(a==3&&b==1&&c==3)ans+=2;
	else if(a==3&&b==3&&c==1)ans+=2;
	else if(a==2&&b==3&&c==3)ans+=2;
	else if(a==3&&b==2&&c==3)ans+=2;
	else if(a==3&&b==3&&c==2)ans+=2;
	else if(a==3&&b==3&&c==3)ans+=3;
	else if(a==0||b==0||c==0){
		ans+=a/3;ans+=b/3;ans+=c/3;
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
