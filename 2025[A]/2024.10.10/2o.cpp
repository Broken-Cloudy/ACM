#include<iostream>
#include<cstdio>
using namespace std;
int zt[1<<11],ztnum,kingnum[1<<11];
int i,j,k,K,N,num,t;
long long f[121][121][19],ans;//f[i][j][k]//i��ʾ������j��ʾ��ǰ����ӵ�е�״̬��k��ʾ�ѷ��õĹ����� 
void Pre(){
	int num,i,j;
	for(i=0;i<(1<<N);i++){
		if(((i&(i<<1))==0)&&((i&(i>>1))==0)){//���������״̬ 
			zt[++ztnum]=i;
			num=0;
			for(j=0;j<N;j++){
				if(i&(1<<j))num++;
			}
			kingnum[ztnum]=num;
		}
	}
	for(i=1;i<=ztnum;i++)f[1][i][kingnum[i]]=1;
}
int main(){
	freopen("2o.in","r",stdin);freopen("2o.out","w",stdout);
	cin>>N>>K;
	Pre();
	for(i=2;i<=N;i++){
		for(k=1;k<=ztnum;k++){//�оٵ�ǰ��״̬�� 
			for(num=kingnum[k];num<=K;num++){ 
				for(t=1;t<=ztnum;t++){//�о���һ��״̬
					if(!((zt[k]<<1)&zt[t])&&!((zt[k]>>1)&zt[t])&&!(zt[k]&zt[t])){
						f[i][k][num]+=f[i-1][t][num-kingnum[k]];
					}
				}
			}
		}
	}
	for(i=1;i<=ztnum;i++)ans+=f[N][i][K];
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
