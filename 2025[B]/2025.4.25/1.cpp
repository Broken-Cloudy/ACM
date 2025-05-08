#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[2009],i,j,GCD,x,y,l,r,t,FF,F,f[2009],k;
queue<int>q;
void gcd(int a,int b){
	if(b==0){
		GCD=a;
		return;
	}
	gcd(b,a%b);
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=1;i<=n;i++){
		if(F==-1)break;
		if(f[i]>0)continue;
		while(!q.empty())q.pop();
		l=r=i;q.push(i);
		while(!q.empty()){
			t=q.front();q.pop();FF=0;
			for(j=l;j<=r;j++){
				if(j==t)continue;
				gcd(a[j],a[t]);
				if(GCD>=2){
					FF=1;
					break;
				}
			}
			if(FF==1)continue;
			q.push(r);r++;
			while(r<=n){
				gcd(a[r],a[t]);
				if(GCD>=2){
					FF=1;
					break;
				}
				q.push(r);r++;
			}
			if(FF==0)break;
		}
		if(FF==1){
			for(j=l;j<=r;j++)f[j]=f[l-1]+1;
		}
		else{
			for(j=i-1;j>=1;j--){
				gcd(a[j],a[i]);
				if(GCD>=2){
					l=j;r=i;
					for(k=l;k<=r;k++)f[k]=f[l];
					break;
				}
			}
		}
		if(f[l]==0)F=-1;
	}
	if(F==-1)printf("%lld\n",F);
	else printf("%lld\n",f[n]);
	fclose(stdin);fclose(stdout);
	return 0;
}
