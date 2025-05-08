#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf1=1000000009LL;
const int inf2=1000000007LL;
int T,n,i,LCP,bh,pow27[1000009],pow2727[1000009];
int H1[1000009],H1ni[1000009],H2[1000009],sum[1000009];
int HH1[1000009],HH1ni[1000009],HH2[1000009];
char a[1000009],b[1000009];
bool checker(int x,int up){
	int ans1=H2[x];
	//len=x;
	int ans2=(H1ni[up-x+1]-H1ni[up+1]*pow27[x]%inf1+inf1)%inf1;
	int aans1=HH2[x];
	int aans2=(HH1ni[up-x+1]-HH1ni[up+1]*pow2727[x]%inf2+inf2)%inf2;
	if(ans1==ans2&&aans1==aans2)return true;
	else return false;
}
int F(int l,int r,int up){
	if(l==r){
		return l;
	}
	else if(l+1==r){
		if(checker(r,up)==1)return r;
		else return l;
	}
	else{
		int mid=(l+r)/2;
		if(checker(mid,up)==1){
			return F(mid,r,up);
		}
		else return F(l,mid,up);
	}
}
int work(int i){
	int K;
	int ans=F(0,i,i);//1--i有多少个相同 
	if(ans==i){
		K=ans+sum[i+1];
	}
	else K=ans;
	return K;
}
signed main(){
	freopen("6.in","r",stdin);freopen("6.out","w",stdout);
	pow27[0]=1;pow2727[0]=1;
	for(i=1;i<=1000000;i++){
		pow27[i]=pow27[i-1]*27;
		pow27[i]%=inf1;
		pow2727[i]=pow2727[i-1]*27;
		pow2727[i]%=inf2;
	}
	cin>>T;
	while(T--){
		scanf("%lld",&n);getchar();
		for(i=1;i<=n;i++)a[i]=getchar();getchar();
		for(i=1;i<=n;i++)b[i]=getchar();
		for(i=1;i<=n;i++){//hash
			H1[i]=(H1[i-1]*27+(a[i]-'a'+1))%inf1;
			H2[i]=(H2[i-1]*27+(b[i]-'a'+1))%inf1;
			HH1[i]=(HH1[i-1]*27+(a[i]-'a'+1))%inf2;
			HH2[i]=(HH2[i-1]*27+(b[i]-'a'+1))%inf2;
		}
		for(i=n;i>=1;i--){//ni hash
			H1ni[i]=(H1ni[i+1]*27+(a[i]-'a'+1))%inf1;
			HH1ni[i]=(HH1ni[i+1]*27+(a[i]-'a'+1))%inf2;
			if(a[i]==b[i]){
				sum[i]=sum[i+1]+1;
			}
			else sum[i]=0;
		}
		LCP=0;bh=1;
		for(i=1;i<=n;i++){
			int kk=work(i);
			if(kk>LCP){
				LCP=kk;bh=i;
			}
		}
		printf("%lld %lld\n",LCP,bh);
		for(i=1;i<=n;i++){
			H1[i]=H2[i]=H1ni[i]=sum[i]=a[i]=b[i]=0;
			HH1[i]=HH2[i]=HH1ni[i]=0;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
