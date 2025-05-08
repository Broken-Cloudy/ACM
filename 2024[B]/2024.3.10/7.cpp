#include<bits/stdc++.h>
using namespace std;
const int INF=1000000009;
int a[409],i,n,sum,f[100009],j,SUM;
bool ff=0;
int main(){
	freopen("7.in","r",stdin);freopen("7.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
	SUM=sum;
	sum/=2;f[0]=0;
	for(i=1;i<=SUM;i++)f[i]=INF;
	for(i=1;i<=n;i++){
		for(j=sum;j>=a[i];j--){
			if(a[i]>sum)break;
			if(f[j-a[i]]!=INF){
				f[j]=0;
			}
		}
	}
	for(i=sum;i>=0;i--){
		if(f[i]!=INF){
			printf("%d\n",SUM-2*i);
			break;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
