#include<stdio.h>
#define int long long
int n,W,i,a[200009],Sum,f[200009];
int max(int x,int y){
	if(x>=y)return x;
	else return y;
}
void dfs(int l,int r){
	int i;
	if(l==r){
		printf("%lld\n",l);
		return;
	}
	else if(l==r-1){
		int ANS=0;
		for(i=0;i<=n;i++)f[i]=0;
		int mid=r;
		for(i=1;i<=n;i++){
			f[i]=max(f[i],ANS);//不选
			if(i-mid>=0&&i+mid<=n+1)f[i]=max(f[i],f[i-mid]+a[i]); 
			ANS=max(ANS,f[i]);
		}
		if(ANS>=W){
			printf("%lld\n",r);
			return;
		}
		else{
			printf("%lld\n",l);
			return;
		}
	}
	else{
		int mid=(l+r)/2;
		int ANS=0;
		for(i=0;i<=n;i++)f[i]=0;
		for(i=1;i<=n;i++){
			f[i]=max(f[i],ANS);//不选
			if(i-mid>=0&&i+mid<=n+1)f[i]=max(f[i],f[i-mid]+a[i]); 
			ANS=max(ANS,f[i]);
		}
		if(ANS>=W){
			dfs(mid,r);
		}
		else{
			dfs(l,mid);
		}
	}
}
signed main(){
	freopen("8.in","r",stdin);freopen("8.out","w",stdout);
	scanf("%lld%lld",&n,&W);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		Sum+=a[i];
	}
	if(Sum<W){
		printf("%lld\n",-1);
	}
	else if(W==0){
		printf("%lld\n",n+1);
	}
	else{
		dfs(1,n+1);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
