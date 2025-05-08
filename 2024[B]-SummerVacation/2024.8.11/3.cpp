#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,i,f;
struct nod{
	long double x,y;
};
nod a[100009];
long double x,y,xx,yy,A,B,C,d,s,r,S,F,p;
long double abss(long double x){
	return max(x,-x);
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);f=0;
		for(i=1;i<=n;i++)scanf("%llf%llf",&a[i].x,&a[i].y);
		scanf("%llf%llf%llf%llf",&x,&y,&xx,&yy);
		S=sqrt((xx-x)*(xx-x)+(yy-y)*(yy-y));
		for(i=1;i<=n;i++){
			p=sqrt((a[i].x-xx)*(a[i].x-xx)+(a[i].y-yy)*(a[i].y-yy));
			if(S>=p){
				f=1;
				break;
			}
		}
		if(f==1){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
