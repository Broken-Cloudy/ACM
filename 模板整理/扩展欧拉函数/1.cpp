#include<bits/stdc++.h>
#define int long long
#define d(k) d=(d*k)%P
#define k(k) k=(k*k)%P
#define a(k) a=(a*k)%P
using namespace std;
int prime[10000009],cnt,i,j,B;//cnt是素数的个数，prime里面全部都是素数 
int flag[10000009],phi[10000009];//flag[i]==0质数
int a,m,len;
char b[20000009],c;
void Pre(){//O(NloglogN)埃氏筛 10^7 
	flag[1]=1;
	for(i=1;i<=10000000;i++)phi[i]=i;
	for(i=2;i<=10000000;i++){
		if(flag[i]==0){
			prime[++cnt]=i;//记录下来 
			for(j=i;j<=10000000;j+=i){
				flag[j]=1;//一下子筛到底 
				phi[j]=phi[j]/i*(i-1);
			}
		}
	}
}
int ksm(int a,int P,int len){
	int d=1,i,k,ans;
	for(i=len;i>=2;i--){
		if(b[i]=='9'){k=a;a(k);d(k);k(k);k(k);k(k);a(k);d(k);}
		else if(b[i]=='8'){k=a;a(k);k(k);k(k);k(k);d(k);a(k);}
		else if(b[i]=='7'){k=a;a(k);d(k);k(k);d(k);k(k);d(k);k(k);a(k);}
		else if(b[i]=='6'){k=a;a(k);k(k);d(k);k(k);d(k);k(k);a(k);}
		else if(b[i]=='5'){k=a;a(k);d(k);k(k);k(k);d(k);k(k);a(k);}
		else if(b[i]=='4'){k=a;a(k);k(k);k(k);d(k);k(k);a(k);}
		else if(b[i]=='3'){k=a;a(k);d(k);k(k);d(k);k(k);k(k);a(k);}
		else if(b[i]=='2'){k=a;a(k);k(k);d(k);k(k);k(k);a(k);}
		else if(b[i]=='1'){k=a;a(k);d(k);k(k);k(k);k(k);a(k);}
		else{k=a;a(k);k(k);k(k);k(k);a(k);}
	}
	k=a;
	for(i=b[1]-'1';i>=1;i--)d(k);
	ans=(d*a)%P;
	return ans;
}
/*
int phii(int n){//O(sqrt(n))
	int ans=n,m=sqrt(n),i;
	for(i=2;i<=m;i++){
		if(n%i==0){
			ans=ans/i*(i-1);
			while(n%i==0)n/=i;	
		}
	}
	if(n>1)ans=ans/n*(n-1);
	return ans;
}
*/
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>a>>m;getchar();c=getchar();
	while(c>='0'&&c<='9'){
		b[++len]=c;
		c=getchar();
	}
	Pre();
	int fff=phi[m];
	if(len>=10){
		for(i=1;i<=len;i++){//O(N)
			B=B*10+(b[i]-'0');
			B%=fff;
		}
		B+=fff;
		memset(b,0,sizeof(b));//O(N)
		len=0;
		while(B){b[++len]=B%10+'0';B/=10;}
		for(i=1;i<=len/2;i++)swap(b[i],b[len-i+1]);
		printf("%lld\n",ksm(a%m,m,len));
	}
	else printf("%lld\n",ksm(a%m,m,len));
	fclose(stdin);fclose(stdout);
	return 0;
}
