#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int x,y;
}ans1[1000009],ans2[100009],f,ans[100009];
int T,n,a[50009],i,j,cnt1,cnt2,haff,len,k1,k2,cnt;
nod add(nod t){
	int x=t.x;
	int y=t.y;
	x++;y--;
	if(y==0){
		haff++;
		y=haff;x=1;
	}
	t.x=x;t.y=y;
	return t;
}
signed main(){
	freopen("3o.in","r",stdin);freopen("3o.out","w",stdout);
	f.x=1;f.y=1;haff=1;
	while(cnt2<=100000){
		cnt2++;
		ans2[cnt2].x=(f.x-1)*3+1;
		ans2[cnt2].y=(f.y-1)*3+1;
		f=add(f);
	}
	for(len=3;len<=1000;len+=3){
		for(i=1;i<len;i++){
			j=len-i;
			if(i%3==0||j%3==0)continue;
			if((i-2)%3==0){
				if((j-2)>=2){
					cnt1++;
					ans1[cnt1].x=i;
					ans1[cnt1].y=j-2;
				}
				cnt1++;
				ans1[cnt1].x=i;
				ans1[cnt1].y=j;
			}
			else{
				cnt1++;
				ans1[cnt1].x=i;
				ans1[cnt1].y=j;
			}
		}
	}
	cin>>T;
	while(T--){
		scanf("%lld",&n);k1=1;k2=1;cnt=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++){
			cnt++;
			if(a[i]==0){
				ans[cnt].x=ans2[k2].x;
				ans[cnt].y=ans2[k2].y;
				k2++;
			}
			else{
				if((ans1[k1].x+ans1[k1].y)<=(ans2[k2].x+ans2[k2].y)){
					ans[cnt].x=ans1[k1].x;
					ans[cnt].y=ans1[k1].y;
					k1++;
				}
				else{
					ans[cnt].x=ans2[k2].x;
					ans[cnt].y=ans2[k2].y;
					k2++;
				}
			}
		}
		for(i=1;i<=n;i++)printf("%lld %lld\n",ans[i].x,ans[i].y);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
