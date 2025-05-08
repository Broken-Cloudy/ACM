#include<bits/stdc++.h>
#define int long long
using namespace std;
struct point{
	int x,y;
};
point p[2009];
int n,q,i,j,GCD,cnt,x,y,dx,dy,vis[1009][1009],ha;
void gcd(int a,int b){
	if(b==0){
		GCD=a;
		return;
	}
	gcd(b,a%b);
}
bool check(int x,int y){
	if(x>0&&x<=n&&y>0&&y<=n)return 1;
	else return 0;
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;q=n*n;
	for(int o=1;o<=q;o++){
		scanf("%lld%lld",&x,&y);
		if(vis[x][y]==1)putchar('0');
		else{
			putchar('1');
			for(i=1;i<=cnt;i++){
				dx=x-p[i].x;dy=y-p[i].y;
				gcd(abs(dx),abs(dy));
				dx/=GCD;dy/=GCD;
				for(j=0;check(x+j*dx,y+j*dy);j++){
					vis[x+j*dx][y+j*dy]=1;
				}
				for(j=0;check(x+j*dx,y+j*dy);j--){
					vis[x+j*dx][y+j*dy]=1;
				}
			}
			cnt++;
			p[cnt].x=x;p[cnt].y=y;
		}
	}
	putchar('\n');
	fclose(stdin);fclose(stdout);
	return 0;
}
