#include<bits/stdc++.h>
#define int long long
#define d(k) d=(d*k)%P
#define k(k) k=(k*k)%P
#define a(k) a=(a*k)%P
using namespace std;
int a,m,cnt;
char b[20000009],c;
int ksm(int a,int P,int len){
	int d=1,i,k,ans;
	for(i=len;i>=2;i--){
		if(b[i]=='9'){k=a;a(k);d(k);k(k);k(k);k(k);a(k);d(k);}
		else if(b[i]=='8'){k=a;a(k);k(k);k(k);k(k);d(k);a(k);}
		else if(b[i]=='7'){k=a;a(k);d(k);k(k);d(k);k(k);d(k);k(k);a(k);}
		else if(b[i]=='6'){k=a;a(k);k(k);d(k);k(k);d(k);k(k);a(k);}
		else if(b[i]=='5'){k=a;a(k);d(k);k(k);k(k);d(k);k(k);a(k);}
		else if(b[i]=='4'){k=a;a(k);k(k);k(k);d(k);k(k);a(k);}
		else if(b[i]=='3'){k=a;a(k);d(k);k(k);d(k);k(k);k(k);a(k);}
		else if(b[i]=='2'){k=a;a(k);k(k);d(k);k(k);k(k);a(k);}
		else if(b[i]=='1'){k=a;a(k);d(k);k(k);k(k);k(k);a(k);}
		else{k=a;a(k);k(k);k(k);k(k);a(k);}
	}
	k=a;
	for(i=b[1]-'1';i>=1;i--)d(k);
	ans=(d*a)%P;
	return ans;
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>a>>m;getchar();c=getchar();
	while(c>='0'&&c<='9'){
		b[++cnt]=c;
		c=getchar();
	}
	printf("%lld\n",ksm(a%m,m,cnt));
	fclose(stdin);fclose(stdout);
	return 0;
}
