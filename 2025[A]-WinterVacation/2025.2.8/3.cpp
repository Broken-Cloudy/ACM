#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,i,v,X,cc;
char c[1000009];
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;getchar();
	for(i=1;i<=n;i++)c[i]=getchar();
	for(i=1;i<=n;i++){
		if(c[i]=='0'){
			v+=10;
			X+=v;
		}
		else if(c[i]=='1'){
			v-=5;
			v=max(v,0LL);
			X+=v;
		}
		else{
			cc=min(10LL,v);
			v-=cc;
			X+=v;
			v+=cc;
		}
	}
	cout<<X<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
