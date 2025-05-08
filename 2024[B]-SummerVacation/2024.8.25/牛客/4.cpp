#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int x,y,bh;
};
nod s[1009],xia[1009],r[1009],yes[1009],no[1009];
int n,k,b,i,x,y,C,j,cnt,nocnt;
int scnt,xcnt,rcnt;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n>>k>>b;
	for(i=1;i<=2*n;i++){
		scanf("%lld%lld",&x,&y);
		C=k*x+b;
		if(C>y){
			scnt++;s[scnt].bh=i;
			s[scnt].x=x;s[scnt].y=y;
		}
		else if(C==y){
			rcnt++;r[rcnt].bh=i;
			r[rcnt].x=x;r[rcnt].y=y;
		}
		else{
			xcnt++;xia[xcnt].bh=i;
			xia[xcnt].x=x;xia[xcnt].y=y;
		}
	}
	while(scnt>0){
		if(xcnt>0){
			cnt++;
			yes[cnt].x=xia[xcnt].bh;yes[cnt].y=s[scnt].bh;
			scnt--;xcnt--;
		}
		else{
			break;
		}
	}
	while(rcnt>0){
		if(xcnt>0){
			cnt++;
			yes[cnt].x=r[rcnt].bh;yes[cnt].y=xia[xcnt].bh;
			rcnt--;xcnt--;
		}
		else if(scnt>0){
			cnt++;
			yes[cnt].x=r[rcnt].bh;yes[cnt].y=s[scnt].bh;
			scnt--;rcnt--;
		}
		else{
			cnt++;
			yes[cnt].x=r[rcnt].bh;yes[cnt].y=r[rcnt-1].bh;
			rcnt-=2;
		}
	}
	while(scnt>0){
		nocnt++;
		no[nocnt].x=s[scnt].bh;no[nocnt].y=s[scnt-1].bh;
		scnt-=2;
	}
	while(xcnt>0){
		nocnt++;
		no[nocnt].x=xia[xcnt].bh;no[nocnt].y=xia[xcnt-1].bh;
		xcnt-=2;
	}
	cout<<cnt<<endl;
	for(i=1;i<=cnt;i++){
		printf("%lld %lld Y\n",yes[i].x,yes[i].y);
	}
	for(i=1;i<=nocnt;i++){
		printf("%lld %lld N\n",no[i].x,no[i].y);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
