#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,x,a,b,c,n,i,j,k,temp[100009][5],ans,te,R;
int r[100009][5];
//temp1���ٻ�+��+�����+�� temp2����+��+�����+��  
//temp3����+��+��+��
int tem[5],l[5];
signed main(){
	freopen("J.in","r",stdin);freopen("J.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++){
		scanf("%lld%lld%lld%lld%lld",&x,&a,&b,&c,&n);
		temp[1][1]=a*x+c;r[1][1]=a*b*x-c;
		temp[1][2]=x+min(b*x,c);r[1][2]=b*x-min(b*x,c);
		temp[1][3]=0;r[1][3]=0;
		ans=0;
		for(i=2;i<=n;i++){
			memset(tem,0,sizeof(tem));
			memset(l,0,sizeof(l));
			for(k=1;k<=3;k++){
				for(j=1;j<=3;j++){
					if(k==1){
						te=temp[i-1][j]+min(r[i-1][j],c);//����̳� 
						R=r[i-1][j]-min(r[i-1][j],c);
						te+=a*x;R+=a*b*x;//����� 
						te+=min(R,c);R-=min(R,c);//����
						if(te>tem[k]){
							tem[k]=te;l[k]=R;
						}
					}
					if(k==2){
						te=temp[i-1][j]+min(r[i-1][j],c);//����̳� 
						R=r[i-1][j]-min(r[i-1][j],c);
						te+=min(R,c);R-=min(R,c);//����
						te+=x;R+=b*x;//����� 
						te+=min(R,c);R-=min(R,c);//����
						if(te>tem[k]){
							tem[k]=te;l[k]=R;
						}
					}
					if(k==3){
						te=temp[i-1][j]+min(r[i-1][j],c);//����̳�
						R=r[i-1][j]-min(r[i-1][j],c);
						te+=min(R,c);R-=min(R,c);//����
						te+=min(R,c);R-=min(R,c);//����
						te+=min(R,c);R-=min(R,c);//����
						if(te>tem[k]){
							tem[k]=te;l[k]=R;
						}
					}
				}
			}
			for(k=1;k<=3;k++){
				temp[i][k]=max(temp[i-1][k],tem[k]);
				r[i][k]=max(r[i-1][k],l[k]);
			}
		}
		ans=max(ans,temp[n][1]);
		ans=max(ans,temp[n][2]);
		ans=max(ans,temp[n][3]);
		printf("%lld\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
