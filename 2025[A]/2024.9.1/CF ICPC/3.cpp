#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1000000009LL;
int p,q,i,j,k,w,x,y,op,ans=inf;
int f[109][109][2];//f[][][0]���һ��,f[][][1]�յ�һ�� 
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>x>>y>>p>>q;
	for(i=0;i<=100;i++){
		for(j=0;j<=100;j++)f[i][j][0]=f[i][j][1]=inf;
	}
	f[0][0][0]=0;
	for(op=1;op<=100;op++){
		//����p������ 
		//0-->1
		for(k=0;k<=p;k++){//������ 
			w=p-k;//������ 
			if(w<0)break;
			for(i=0;i<=x;i++){//��
				for(j=0;j<=y;j++){//��
					if(i-w>=0&&j-k>=0&&((x-i)+q>=(y-j)||x-i==0)){
						f[i][j][1]=min(f[i][j][1],f[i-w][j-k][0]+1);
					}
				}
			}
		}	
		//1-->0
		for(k=0;k<=p;k++){//������ 
			for(i=0;i<=x;i++){//��
				for(j=0;j<=y;j++){//��
					if(j+k<=y&&(i+q>=j||i==0)){
						f[i][j][0]=min(f[i][j][0],f[i][j+k][1]+1);
					}
				}
			}
		}
	}
	for(i=0;i<=y;i++)ans=min(ans,f[x][i][1]);
	if(ans==inf)cout<<-1<<endl;
	else cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
