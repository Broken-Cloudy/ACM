#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,m,n,i,k1,k2,x,y,ans,cnt,a0,a1,b0,b1,ANS;
short c[1000009],a[1000009],b[1000009];
char ch;
struct nod{
	short a,b;
}A[1000009];
bool cmp(nod x,nod y){
	if(x.a==y.a)return x.b<y.b;
	else return x.a<y.a;
}
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n>>x>>y;
	getchar();for(i=1;i<=n;i++){ch=getchar();a[i]=ch-'0';}
	getchar();for(i=1;i<=n;i++){ch=getchar();b[i]=ch-'0';}
	getchar();for(i=1;i<=n;i++){ch=getchar();c[i]=ch-'0';}
	for(i=1;i<=n;i++){
		if((a[i]^b[i])!=c[i]){
			cnt++;
			A[cnt].a=a[i];A[cnt].b=b[i];
		}
	}
	sort(A+1,A+1+cnt,cmp);
	for(i=1;i<=cnt;i++){
		if(A[i].a==0)a0++;
		else a1++;
	}
	if(a0>=a1){
		for(i=1;i<=cnt;i++){
			if(A[i].a==0){
				if(A[i].b==0)b0++;
				else b1++;
			}
		}
	}
	else{
		for(i=1;i<=cnt;i++){
			if(A[i].a==1){
				if(A[i].b==0)b0++;
				else b1++;
			}
		}
	}
	ans=min(a0,a1)+min(b0,b1);
	ans=min(ans,cnt/2);
	ANS=ans*y+(cnt-2*ans)*x;
	ANS=min(ANS,cnt*x);
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
