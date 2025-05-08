#include<bits/stdc++.h>
using namespace std;
long long T,i,j,m,n,a[200009],b[200009],D,x,y;
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld%lld",&n,&m);
		D=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(j=1;j<=m;j++){
			scanf("%lld",&b[j]);
		}
		sort(a+1,a+1+n);sort(b+1,b+1+m);
		i=1;j=n;x=1;y=m;
		while(i<=j){//对应a的序号 
			int amin1=max(b[x]-a[i],a[i]-b[x]);
			int amin2=max(b[y]-a[i],a[i]-b[y]);
			int amax1=max(b[x]-a[j],a[j]-b[x]);
			int amax2=max(b[y]-a[j],a[j]-b[y]);
			if(max(amin1,amin2)>=max(amax1,amax2)){//a的小 赢 
				D+=max(amin1,amin2);
				i++;
				if(amin1>=amin2)x++;
				else y--;
			}
			else{//a的大 赢 
				D+=max(amax1,amax2);
				j--;
				if(amax1>=amax2)x++;
				else y--;
			}
		}
		printf("%lld\n",D);
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
