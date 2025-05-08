#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,x,y,a[400009];
void work(int x,int y){
	int i;
	if(y-x==1){1;}
	else if(y-x==2){
		a[x+1]=2;
	}
	else if((y-x)%2==1){
		for(i=x+1;i<=y-1;i++){
			a[i]=(!a[i-1]);
		}
	}
	else{
		a[x+1]=(!a[x]);a[x+2]=2;a[x+3]=a[x];
		for(i=x+4;i<=y-1;i++){
			a[i]=(!a[i-1]);
		}
	}
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld",&n,&x,&y);
		for(i=1;i<=2*n;i++)a[i]=-1;
		a[x]=a[x+n]=0;a[y]=a[y+n]=1;
		work(x,y);
		work(y,x+n);
		for(i=1;i<=n;i++){
			if(a[i]==-1)a[i]=a[i+n];
			else a[i+n]=a[i];
		}
		for(i=1;i<=n;i++){
			if(i!=n)printf("%lld ",a[i]);
			else printf("%lld\n",a[i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
