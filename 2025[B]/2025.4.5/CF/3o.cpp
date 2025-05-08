#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX_N=2009;
struct nod{
	int x,y;
}ans[MAX_N];
int T,n,i,a[MAX_N],b[MAX_N],cnt,bh[MAX_N],x,y;
bool F,FF;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);cnt=0;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++)scanf("%lld",&b[i]),bh[b[i]]=i;
		FF=1;
		if(n%2==1){
			F=0;
			for(i=1;i<=n/2;i++){
				if(a[i]!=b[n-i+1]){
					if(i==bh[a[i]]){
						if(F==0){
							cnt++;
							x=bh[a[i]];
							y=n/2+1;
							ans[cnt].x=x;ans[cnt].y=y;
							swap(a[x],a[y]);
							swap(bh[b[x]],bh[b[y]]);
							swap(b[x],b[y]);
							F=1;
						}
						else FF=0;
					}
					else{
						cnt++;
						x=bh[a[i]];
						y=n-i+1;
						ans[cnt].x=x;ans[cnt].y=y;
						swap(a[x],a[y]);
						swap(bh[b[x]],bh[b[y]]);
						swap(b[x],b[y]);
					}
				}
			}
		}
		else{
			F=1;
			for(i=1;i<=n/2;i++){
				if(a[i]!=b[n-i+1]){
					if(i==bh[a[i]]){
						if(F==0){
							cnt++;
							x=bh[a[i]];
							y=n/2+1;
							ans[cnt].x=x;ans[cnt].y=y;
							swap(a[x],a[y]);
							swap(bh[b[x]],bh[b[y]]);
							swap(b[x],b[y]);
							F=1;
						}
						else FF=0;
					}
					else{
						cnt++;
						x=bh[a[i]];
						y=n-i+1;
						ans[cnt].x=x;ans[cnt].y=y;
						swap(a[x],a[y]);
						swap(bh[b[x]],bh[b[y]]);
						swap(b[x],b[y]);
					}
				}
			}
		}
		for(i=1;i<=n/2;i++){
			if(a[i]!=b[n-i+1])FF=0;
		}
		if(FF==0)printf("-1\n");
		else{
			printf("%lld\n",cnt);
			for(i=1;i<=cnt;i++){
				printf("%lld %lld\n",ans[i].x,ans[i].y);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
