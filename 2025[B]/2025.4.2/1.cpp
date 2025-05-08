#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int T,i,j,k,a[200009],b[200009],n,f[200009],aa,bb,cc,dd,p,anss;
int f_max[23][200009],f_min[23][200009],P2[200009],kk;
void Pre(){
	kk=2;P2[1]=0;//P2向下取整 
	for(i=2;i<=200000;i++){//优化log2到O(1) 
		if(i>=kk){
			P2[i]=P2[i-1]+1;
			kk*=2;
		}
		else P2[i]=P2[i-1];
	}
}
void build1(){//amax
	int i,p,len;
	for(i=1;i<=n;i++)f_max[0][i]=a[i];
	for(p=1;p<=P2[n];p++){
		len=(1LL<<p);
		for(i=1;i<=n-len+1;i++){
			f_max[p][i]=max(f_max[p-1][i],f_max[p-1][i+(1LL<<(p-1))]);
		}
	}
}
void build2(){//bmin
	int i,p,len;
	for(i=1;i<=n;i++)f_min[0][i]=b[i];
	for(p=1;p<=P2[n];p++){
		len=(1LL<<p);
		for(i=1;i<=n-len+1;i++){
			f_min[p][i]=min(f_min[p-1][i],f_min[p-1][i+(1LL<<(p-1))]);
		}
	}
}
int sum1(int x,int y){
	p=P2[y-x+1];
	anss=max(f_max[p][x],f_max[p][y-(1LL<<p)+1]);
	return anss;
}
int sum2(int x,int y){
	p=P2[y-x+1];
	anss=min(f_min[p][x],f_min[p][y-(1LL<<p)+1]);
	return anss;
}
int check(int x,int y,int kk){
	int anss=0;
	while(x>kk){
		anss++;
		if(1000000000000000001LL/y<=kk)kk=1000000000000000001LL;
		else kk*=y;
	}
	return anss;
}
int pOw(int a,int p){
	int anss=1LL;
	if(p==0)return 1LL;
	else{
		while(p>1){
			if(p%2==1){
				p--;
				anss*=a;
			}
			else{
				p/=2;
				a=a*a;
			}
		}
		anss*=a;
		return anss;
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	Pre();
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++)f[i]=1000000000000000001LL;
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);build1();
		for(i=1;i<=n;i++)scanf("%lld",&b[i]);build2();
		for(i=1;i<=n;i++){//200000
			
		}
		printf("%lld\n",f[n]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
