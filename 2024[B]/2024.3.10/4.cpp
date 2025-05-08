#include<bits/stdc++.h>
using namespace std;
long long a,b,c;
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>a>>b>>c;
	int sum=a+b+c;
	if(sum==1){
		printf("YES\n");
		printf("%lld\n",0);
	}
	else if(a>=1&&b==0&&c==0){
		printf("YES\n");
		printf("%lld\n",1);
	}
	else if(b>=1&&a==0&&c==0){
		printf("YES\n");
		printf("%lld\n",sum-1);
	}
	else if(b>=1&&a>=1&&c==0){
		printf("YES\n");
		printf("%lld\n",sum+sum-1);
	}
	else{
		printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
