#include<bits/stdc++.h>
#define int long long
using namespace std;
int x,y,z,a,b,t,i;
int qian,ans;
int f;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>x>>y>>z>>a>>b>>t;
	for(i=1;i<=t;i++){
		if(i-f>=z)f=0;
		if(i%x==0)qian+=a;
		if(i%y==0&&f==0){//�̵꿪 
			f=i;
			if(qian>b)qian-=b,ans+=b;
			else qian=0,ans+=qian;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
