#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,l,r,I,k,ans,j;
int work(int a,int R){
	int x,num=0,i;
	if(R==0)return 0LL;
	if(a>=I){//大 
		bool ff;
		if((R&(1LL<<a))==0)ff=1;//偏小一个
		else ff=0;
		if((R>>(a+1))==0&&ff==1)return 0;
		if(ff==1)num=(((R>>(a+1))-1LL)<<a)+((1LL<<a)-1LL);
		else num=((R>>(a+1))<<a)+(R%(1LL<<a));
		num-=(((num%(1LL<<I))>=k?1LL:0LL)+(num>>I));num++;
		return num;
	}
	else{//小 
		if(((1LL<<a)&(k))==0){//随便来 
			bool ff;
			if((R&(1LL<<a))==0)ff=1;//偏小一个
			else ff=0;
			if((R>>(a+1))==0&&ff==1)return 0;
			if(ff==1)num=(((R>>(a+1))-1LL)<<a)+((1LL<<a)-1LL);
			else num=((R>>(a+1))<<a)+(R%(1LL<<a));
			num++;
			return num;
		}
		else{
			bool ff;
			int jud=((k>>(a+1))<<a)+(k%(1LL<<a));//挖掉1个 
			if((R&(1LL<<a))==0)ff=1;//偏小一个
			else ff=0;
			if((R>>(a+1))==0&&ff==1)return 0;
			if(ff==1)num=(((R>>(a+1))-1LL)<<a)+((1LL<<a)-1LL);
			else num=((R>>(a+1))<<a)+(R%(1LL<<a));
			num-=(((num%(1LL<<(I-1)))>=jud?1LL:0LL)+(num>>(I-1)));num++;
			return num;
		}
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld%lld",&l,&r,&I,&k);ans=0;
		for(j=0;(1LL<<j)<=r;j++){
			if((work(j,r)-work(j,l-1))%2==1){
				ans+=(1LL<<j);
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
