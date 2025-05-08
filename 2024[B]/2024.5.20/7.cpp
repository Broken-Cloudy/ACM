#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int x,y;
};
nod a[1000009];
bool cmp(nod x,nod y){
	return x.x<y.x;
}
int n,i,y,yy,sum1,sum2,x,xx,N,cnt;
signed main(){
	freopen("7.in","r",stdin);freopen("7.out","w",stdout);
	cin>>N;
	for(i=1;i<=100000;i++){
		y=i-1;
		yy=-i-1;
		if(y!=0){
			sum1=i*i;
			if(N%sum1==0){
				x=N/sum1*y;
				cnt++;
				a[cnt].x=x;a[cnt].y=y;
			}
		}
		if(yy!=0){
			sum2=i*i;
			if(N%sum2==0){
				xx=N/sum2*yy;
				cnt++;
				a[cnt].x=xx;a[cnt].y=yy;
			}
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(i=1;i<=cnt;i++){
		printf("(%lld, %lld)\n",a[i].x,a[i].y);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
