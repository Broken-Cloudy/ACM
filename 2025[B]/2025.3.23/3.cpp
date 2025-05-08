#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[50009],i,haff,num,now;
struct nod{
	int x,y;
}ans[50009],Big;
nod add(nod t){
	int x=t.x;
	int y=t.y;
	x--;y++;
	if(x==0){
		haff++;
		x=haff;y=1;
	}
	t.x=x;t.y=y;
	return t;
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);Big.x=1;Big.y=1;haff=1;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++){
			if(a[i]==1){
				num=Big.x+Big.y-1;
				num+=(Big.y-1);//指向第几个 
				if(i>(num-1)*4){
					ans[i].x=(Big.x-1)*3+1;
					ans[i].y=(Big.y-1)+1;
					Big=add(Big);
				}
				else{
					now=i-num;
				}
			}
			else{//刁钻0 
				ans[i].x=(Big.x-1)*3+1;
				ans[i].y=(Big.y-1)+1;
				Big=add(Big);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
