#include<bits/stdc++.h>
#define int long long
#define d(k) d=(d*k)%P
#define k(k) k=(k*k)%P
#define a(k) a=(a*k)%P
using namespace std;
const int P=10007;
int i,j,n,arr[1234569];
int phi[100009],anss,prime[100009],flag[100009],cnt;
int m,len;
void Pre(){//O(NloglogN)埃氏筛 10^7
	flag[1]=1;
	for(i=1;i<=100000;i++)phi[i]=i;
	for(i=2;i<=100000;i++){
		if(flag[i]==0){
			prime[++cnt]=i;//记录下来 
			for(j=i;j<=100000;j+=i){
				flag[j]=1;//一下子筛到底 
				phi[j]=phi[j]/i*(i-1);
			}
		}
	}
}
int ksm(int a,int b,int P){
	int d=1,i,k,ans,c;
	while(b>=10){
		c=b%10;
		if(c==9){k=a;a(k);d(k);k(k);k(k);k(k);a(k);d(k);}
		else if(c==8){k=a;a(k);k(k);k(k);k(k);d(k);a(k);}
		else if(c==7){k=a;a(k);d(k);k(k);d(k);k(k);d(k);k(k);a(k);}
		else if(c==6){k=a;a(k);k(k);d(k);k(k);d(k);k(k);a(k);}
		else if(c==5){k=a;a(k);d(k);k(k);k(k);d(k);k(k);a(k);}
		else if(c==4){k=a;a(k);k(k);k(k);d(k);k(k);a(k);}
		else if(c==3){k=a;a(k);d(k);k(k);d(k);k(k);k(k);a(k);}
		else if(c==2){k=a;a(k);k(k);d(k);k(k);k(k);a(k);}
		else if(c==1){k=a;a(k);d(k);k(k);k(k);k(k);a(k);}
		else{k=a;a(k);k(k);k(k);k(k);a(k);}
		b/=10;
	}
	k=a;
	for(i=b-1;i>=1;i--)d(k);
	ans=(d*a)%P;
	return ans;
}
int dfs(int ai,int bi,int P){
	int ans,a,b;
	if(P==1)return 1;
	if(bi==n){
		a=arr[ai];b=arr[bi];
		if(b==0)return 1;
		if(b>=phi[P])b=b%phi[P]+phi[P];
		ans=ksm(a,b,P);
	}
	else{
		a=arr[ai];
		b=dfs(ai+1,bi+1,phi[P]);
		if(b==0)return 1;
		if(b>=phi[P])b=b%phi[P]+phi[P];
		ans=ksm(a,b,P);
	}
	return ans+P;
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n;Pre();
	for(i=1;i<=n;i++){
		scanf("%lld",&arr[i]);
	}
	anss=dfs(1,2,10007)%10007;
	printf("%lld\n",anss);
	fclose(stdin);fclose(stdout);
	return 0;
}
