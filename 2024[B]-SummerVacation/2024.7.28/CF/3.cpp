#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[200009],i,b[200009],c[200009],cnt,f=0,j,sum,y,cnt2;
int op[49];
int abss(int x){
	return max(x,-x);
}
bool check(){
	int i;
	bool x=1;
	for(i=1;i<=cnt;i++){
		if(b[i]!=0){
			x=0;
			break;
		}
	}
	return x;
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	a[0]=-1;b[0]=-1;
	while(T--){
		scanf("%lld",&n);cnt=0;f=0;
		memset(op,0,sizeof(op));
		for(i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(i=1;i<=n;i++){
			if(a[i]!=a[i-1]){
				b[++cnt]=a[i];
			}
		}
		sort(b+1,b+1+cnt);
		for(i=1;i<=41;i++){
			if(i==41){
				f=1;
				break;
			}
			else{
				if(cnt==1){
					if(b[cnt]!=0){
						op[++op[0]]=b[cnt];
						cnt=0;
					}
					break;
				}
				if(cnt%2==0)y=(b[cnt/2+1]+b[cnt/2])/2;
				else y=b[cnt/2+1];
				op[++op[0]]=y;
				for(j=1;j<=cnt;j++){
					b[j]=abss(b[j]-y);
				}
				sort(b+1,b+1+cnt);
				cnt2=0;
				for(j=1;j<=cnt;j++){
					if(b[j]!=b[j-1]){
						c[++cnt2]=b[j];
					}
				}
				for(j=1;j<=cnt2;j++){
					b[j]=c[j];
				}
				for(j=cnt2+1;j<=cnt;j++)b[j]=0;
				cnt=cnt2;
			}
		}
		if(f==1||op[0]>40){
			printf("-1\n");
		}
		else{
			printf("%lld\n",op[0]);
			for(i=1;i<=op[0];i++){
				if(i==op[0])printf("%lld\n",op[i]);
				else{
					printf("%lld ",op[i]);
				}
			}
			if(op[0]==0)printf("\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
