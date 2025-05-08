#include<iostream>
#include<cstdio>
using namespace std;
long long a[200009],n,i,maxx,sum,gcd;
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxx=max(maxx,a[i]);
		sum+=a[i];
	}
	for(i=1;i<=maxx;i++){
		if(sum%i==0){
			if(i*n<=sum){
				gcd++;
			}
			else break;
		}
	}
	cout<<gcd<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
