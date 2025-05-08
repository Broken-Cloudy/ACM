#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int W,I,N,G,j,k,slen,len,r,l;
string w[19],ii[19],n[19],g[19],S;
char s[209];
bool f[209][209][255];
void check(int i,int k,int j){
	if(f[i][j]['W']==1&&f[i][j]['I']==1&&f[i][j]['N']==1&&f[i][j]['G']==1)return;
	else{
		int x,y,z;
		char a[5],b[5];
		memset(a,0,sizeof(a));memset(b,0,sizeof(b));
		if(f[i][k]['W']==1)a[1]='W';if(f[i][k]['I']==1)a[2]='I';
		if(f[i][k]['N']==1)a[3]='N';if(f[i][k]['G']==1)a[4]='G';
		if(f[k+1][j]['W']==1)b[1]='W';if(f[k+1][j]['I']==1)b[2]='I';
		if(f[k+1][j]['N']==1)b[3]='N';if(f[k+1][j]['G']==1)b[4]='G';
		for(x=1;x<=4;x++){
			if(a[x]==0)continue;//直接从超时到AC 
			for(y=1;y<=4;y++){
				if(b[y]==0)continue;//直接从超时到AC 
				S.erase(0);
				S.insert(0,1,a[x]);
				S.insert(1,1,b[y]);
				if(f[i][j]['W']==0){
					for(z=1;z<=W;z++){
						if(S==w[z]){
							f[i][j]['W']=1;
							break;
						}
					}
				}
				if(f[i][j]['I']==0){
					for(z=1;z<=I;z++){
						if(S==ii[z]){
							f[i][j]['I']=1;
							break;
						}
					}
				}
				if(f[i][j]['N']==0){
					for(z=1;z<=N;z++){
						if(S==n[z]){
							f[i][j]['N']=1;
							break;
						}
					}
				}
				if(f[i][j]['G']==0){
					for(z=1;z<=G;z++){
						if(S==g[z]){
							f[i][j]['G']=1;
							break;
						}
					}
				}
			}
		}
	}
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>W>>I>>N>>G;
	for(j=1;j<=W;j++)cin>>w[j];for(j=1;j<=I;j++)cin>>ii[j];
	for(j=1;j<=N;j++)cin>>n[j];for(j=1;j<=G;j++)cin>>g[j];
	scanf("%s",s+1);slen=strlen(s+1);
	for(j=1;j<=slen;j++)f[j][j][s[j]]=1;
	for(len=2;len<=slen;len++){
		for(j=1;j<=slen-len+1;j++){
			k=j+len-1;
			for(r=j;r<k;r++){
				check(j,r,k);
			}
		}
	}
	if(f[1][slen]['W']==1)putchar('W');
	if(f[1][slen]['I']==1)putchar('I');
	if(f[1][slen]['N']==1)putchar('N');
	if(f[1][slen]['G']==1)putchar('G');
	if(f[1][slen]['W']==0&&f[1][slen]['I']==0&&f[1][slen]['N']==0&&f[1][slen]['G']==0)printf("The name is wrong!\n");
	fclose(stdin);fclose(stdout);
	return 0;
}
