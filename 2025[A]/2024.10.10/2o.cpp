#include<iostream>
#include<cstdio>
using namespace std;
int zt[1<<11],ztnum,kingnum[1<<11];
int i,j,k,K,N,num,t;
long long f[121][121][19],ans;//f[i][j][k]//i表示行数，j表示当前行数拥有的状态，k表示已放置的国王数 
void Pre(){
	int num,i,j;
	for(i=0;i<(1<<N);i++){
		if(((i&(i<<1))==0)&&((i&(i>>1))==0)){//符合题意的状态 
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
		for(k=1;k<=ztnum;k++){//列举当前行状态数 
			for(num=kingnum[k];num<=K;num++){ 
				for(t=1;t<=ztnum;t++){//列举上一行状态
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
