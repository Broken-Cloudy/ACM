#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,i,Left,Right,Ans;
int r[100009],d[100009],D[100009],R[100009],DR,cnte[100009];
char c[100009];
void Pre(){
	int i,j;
	for(i=1;i<=n;i++){//r前缀和 
		r[i]=r[i-1];
		if(c[i]=='r')r[i]++;
	}
	for(i=n;i>=1;i--){//d后缀和 
		d[i]=d[i+1];
		if(c[i]=='d')d[i]++;
	}
	for(i=1;i<=n;i++){//e d[i]前缀和D r[i]前缀和R r[i]*d[i]前缀和DR 
		D[i]=D[i-1];R[i]=R[i-1];cnte[i]=cnte[i-1];
		if(c[i]=='e'){
			D[i]+=d[i];
			R[i]+=r[i];
			DR+=d[i]*r[i];//相当于直接求 
			cnte[i]++;
		}
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>q;getchar();
	for(i=1;i<=n;i++)c[i]=getchar();
	Pre();
	while(q--){
		scanf("%lld%lld",&Left,&Right);
		Ans=DR;//x=(r[Left-1]+r[Right]) y=(d[Right+1]+d[Left])
		Ans+=(cnte[Right]-cnte[Left-1])*(r[Left-1]+r[Right])*(d[Right+1]+d[Left]);
		Ans-=(r[Left-1]+r[Right])*(D[Right]-D[Left-1]);
		Ans-=(d[Right+1]+d[Left])*(R[Right]-R[Left-1]);
		printf("%lld\n",Ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
