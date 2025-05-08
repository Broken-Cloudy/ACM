#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n,len,i,ans,m,cnt,bh,zhong;
struct nod{
	ll x,y;
};
bool zuo,you,zz,yy;
nod a[100009];
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld",&n);
		zuo=you=zz=yy=zhong=0;
		map<ll,int>q;
		for(i=1;i<=n;i++){
			scanf("%lld%lld",&a[i].x,&a[i].y);
			if(a[i].y==0)zz=1,yy=1;
			if(a[i].y==0||a[i].x==1&&a[i].y==1||a[i].x==1&&a[i].y==-1)zhong++;
			if(a[i].y<0)zz=1;if(a[i].y>0)yy=1;
			if(q[a[i].y]==0)q[a[i].y]=a[i].x;
			else{
				if(a[i].y<0)zuo=1;
				else you=1;
				q[a[i].y]=3;
			}
			if(q[a[i].y-1]==1&&q[a[i].y]==2||q[a[i].y-1]==2&&q[a[i].y]==1){
				if(a[i].y<=0)zuo=1;
				else you=1;
			}
			if(q[a[i].y+1]==1&&q[a[i].y]==2||q[a[i].y+1]==2&&q[a[i].y]==1){
				if(a[i].y>=0)you=1;
				else zuo=1;
			}
		}
		if(zuo==1&&you==1||zhong==3)printf("0\n");
		else if(zuo==1&&yy==1||zhong==2||zz==1&&you==1)printf("1\n");
		else if(zz==1&&yy==1||zz==0&&you==1||yy==0&&zuo==1||zhong==1)printf("2\n");
		else printf("3\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
