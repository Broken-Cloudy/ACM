#include<bits/stdc++.h>
using namespace std;
long long w[509],i,n,c2[200009],c1[200009],j,sum[509],ans;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&w[i]);
		sum[i]=sum[i-1]+w[i];
	}
	c1[w[1]]=1;
	for(i=2;i<=n;i++){
		c2[w[i]]++;
		for(j=0;j<=sum[i];j++){
			c2[j]+=c1[j];//不选 
			c2[j+w[i]]+=c1[j];//选一次 
			c2[max(j-w[i],w[i]-j)]+=c1[j];
		}
		for(j=0;j<=sum[i];j++){
			c1[j]=c2[j];
			c2[j]=0;
		}
	}
	for(i=1;i<=sum[n];i++){
		if(c1[i]!=0){
			ans++;
		}
	}
	printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
} 
