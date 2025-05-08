#include<iostream>
#include<cstdio>
using namespace std;
int T,i,j;
long long n,ans,b[20009],c[20009],d[20009],cnt2,cnt1,r[290][2009],x=0;
int main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>T;
	for(i=1;i<=201;i++){
		for(j=1;j<=i;j++){
			r[i][j]=x;
			x++;
		}
		x-=300;
	}
	for(int o=1;o<=T;o++){
		ans=0; 
		scanf("%lld",&n);
		if(n==5){
			printf("%d\n",3);
			printf("0 -1 1\n");
			continue;
		}
		while(n>0){
			long long k=1,cnt=0;
			while(k*2<=n){
				k*=2;
				cnt++;
			}
			if(n==3){
				b[++ans]=-10000009; 
				b[++ans]=-10000006; 
				n=0;
			}
			else if(n-k==1){
				for(i=cnt;i>=1;i--){ 
					b[++ans]=r[cnt][i]; 
				}
				for(i=1;i<=cnt-1;i++){
					b[++ans]=r[cnt-1][i];
				}
				n=0;
			}
			else{
				for(i=1;i<=cnt;i++){
					b[++ans]=r[cnt][i];
				}
				n-=k;
			}
		}
		printf("%d\n",ans);
		for(i=1;i<=ans;i++){
			if(i!=ans)printf("%d ",b[i]);
			else printf("%d\n",b[i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
