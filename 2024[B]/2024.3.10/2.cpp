#include<bits/stdc++.h>
using namespace std;
int n,ci,i;
double p=0.97,P=1.0;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	n-=5;
	ci=n/2;
	for(i=1;i<=ci;i++){
		P*=p;
	}
	printf("%.3lf\n",(1-P));
	fclose(stdin);fclose(stdout);
	return 0;
}
