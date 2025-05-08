#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[4][4],b[12],i,j,kk,x,y,t,ss;
int check(int x){
	if(x==6)return 10000;
	else if(x==7)return 36;
	else if(x==8)return 720;
	else if(x==9)return 360;
	else if(x==10)return 80;
	else if(x==11)return 252;
	else if(x==12)return 108;
	else if(x==13)return 72;
	else if(x==14)return 54;
	else if(x==15)return 180;
	else if(x==16)return 72;
	else if(x==17)return 180;
	else if(x==18)return 119;
	else if(x==19)return 36;
	else if(x==20)return 306;
	else if(x==21)return 1080;
	else if(x==22)return 144;
	else if(x==23)return 1800;
	else return 3600;
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	for(i=1;i<=3;i++){
		for(j=1;j<=3;j++){
			scanf("%lld",&a[i][j]);
			b[a[i][j]]=1;
		}
	}
	for(i=1;i<=9;i++)if(b[i]==0)kk=i;
	for(i=1;i<=3;i++){
		for(j=1;j<=3;j++){
			if(a[i][j]==0)a[i][j]=kk;
		}
	}
	cin>>x>>y;
	printf("%lld\n",a[x][y]);
	cin>>x>>y;
	printf("%lld\n",a[x][y]);
	cin>>x>>y;
	printf("%lld\n",a[x][y]);
	cin>>ss;
	if(ss==1)t=a[1][1]+a[1][2]+a[1][3];
	else if(ss==2)t=a[2][1]+a[2][2]+a[2][3];
	else if(ss==3)t=a[3][1]+a[3][2]+a[3][3];
	else if(ss==4)t=a[1][1]+a[2][1]+a[3][1];
	else if(ss==5)t=a[1][2]+a[2][2]+a[3][2];
	else if(ss==6)t=a[1][3]+a[2][3]+a[3][3];
	else if(ss==7)t=a[1][1]+a[2][2]+a[3][3];
	else t=a[2][2]+a[1][3]+a[3][1];
	printf("%lld\n",check(t));
	fclose(stdin);fclose(stdout);
	return 0;
}
