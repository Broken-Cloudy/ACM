#include<bits/stdc++.h>
using namespace std;
long long T,i,n,m,a,b,r,d[68],j,A[68],B[68],work[68],ans;
int main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	for(long long o=1;o<=T;o++){
		ans=1e18+9;
		scanf("%lld%lld%lld",&a,&b,&r);
		long long k=max(a,b),cnt=0;
		while(k>0){
			k=k>>1;cnt++;
		}
		memset(d,0x7f,sizeof(d));
		memset(work,0x7f,sizeof(work));
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		A[0]=a;B[0]=b;work[0]=0;
		for(i=0;i<=cnt;i++){//i=0²»²Ù×÷ 
			if(k>r)break;
			for(j=0;j<i;j++){
				long long aa=A[j]^k;
				long long bb=B[j]^k;
				if(i>=1&&((aa>>(i-1))%2)!=(bb>>(i-1))%2){
					if(max(aa-bb,bb-aa)<=d[i]&&work[j]+k<=r){
						work[i]=work[j]+k;
						A[i]=aa;B[i]=bb;
						d[i]=max(aa-bb,bb-aa);
					}
				}
				if(max(A[j]-B[j],B[j]-A[j])<=d[i]){
					work[i]=work[j];
					A[i]=A[j];B[i]=B[j];
					d[i]=max(A[j]-B[j],B[j]-A[j]);
				}
			}
			if(k==0)k=1;
			else k=k<<1;
		}
		for(i=0;i<=cnt;i++)ans=min(ans,d[i]);
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
