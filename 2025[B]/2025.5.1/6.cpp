#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int FF;
struct nod{
	int bh,val;
}b[1000009];
bool cmp(nod x,nod y){
	return x.val<y.val;
}
bool cmp2(nod x,nod y){
	return x.bh<y.bh;
}
int T,n,i,l,r,p,j,q,f[1000009],maxx1,maxx2,mini1,mini2;
signed main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);l=1;r=n;FF=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&b[i].val);
			b[i].bh=i;f[i]=b[i].val;
		}
		sort(b+1,b+1+n,cmp);
		if(b[1].val==0){
			for(i=1;i<=n;i++){
				if(b[i].val==0){
					b[i].val=-r;
					r--;
				}
				else{
					j=i;p=b[i].val;
					break;
				}
			}
			for(i=j;i<=n;i++){
				if(b[i].val!=p){
					q=b[i].val;
				}
			}
			for(i=j;i<=n;i++){
				if(b[i].val==p){
					b[i].val=-l;
					l++;
				}
				else if(b[i].val==q){
					b[i].val=r;
					r--;
				}
				else{
					FF=1;
					break;
				}
			}
			sort(b+1,b+1+n,cmp2);maxx1=maxx2=0;
			for(i=1;i<=n;i++)maxx1=max(maxx1,b[i].val);
			for(i=1;i<=n;i++)maxx2=max(maxx2,f[i]);
			if(maxx1!=maxx2)FF=1;
		}
		else if(b[n].val==n){
			for(i=n;i>=1;i--){
				if(b[i].val==n){
					b[i].val=r;
					r--;
				}
				else{
					j=i;p=b[i].val;
					break;
				}
			}
			for(i=j;i>=1;i--){
				if(b[i].val!=p){
					q=b[i].val;
				}
			}
			for(i=j;i>=1;i--){
				if(b[i].val==p){
					b[i].val=l;
					l++;
				}
				else if(b[i].val==q){
					b[i].val=-r;
					r--;
				}
				else{
					FF=1;
					break;
				}
			}
			sort(b+1,b+1+n,cmp2);mini1=mini2=9999999;
			for(i=1;i<=n;i++)mini1=min(mini1,b[i].val);
			for(i=1;i<=n;i++)mini2=min(mini2,f[i]);
			if(mini1!=mini2)FF=1;
		}
		else FF=1;
		if(FF==0){
			printf("YES\n");
			for(i=1;i<=n;i++){
				if(i==n)printf("%lld\n",b[i].val);
				else printf("%lld ",b[i].val);
			}
		}
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
