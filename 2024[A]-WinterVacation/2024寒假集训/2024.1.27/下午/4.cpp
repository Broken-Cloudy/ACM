#include<iostream>
#include<cstdio>
using namespace std;
int a,b,ans,d=1,h,pow[10],i;
struct nod{
	int gb,num,ans;
};
const int inf=7000006;
nod k[7000010];
bool vis[1000010][7];
int getnm(int x,int y){
	return x/pow[y]%10;
}
int change(int x,int y,int z){
	int l1,l2;
	l1=z/pow[x]%10;l2=z/pow[y]%10;
	z=z-l1*pow[x]+l2*pow[x];
	z=z-l2*pow[y]+l1*pow[y];
	return z;
}
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>a>>b;
	pow[0]=1000000;
	for(i=1;i<=7;i++)pow[i]=pow[i-1]/10;
	k[++h].num=a;
	k[h].gb=1;
	while(true){
		d%=inf;
		int t=k[d].num;
		int u=k[d].gb;
		if(t==b){
			ans=k[d].ans;
			break;
		}
		if(vis[t][u]==1){
			d++;
			continue;
		}
		else{
			vis[t][u]=1;
		}
		if(getnm(t,u)<9){
			if(vis[t+pow[u]][u]==0){
				h++;h%=inf;
				k[h].num=t+pow[u];
				k[h].gb=u;	
				k[h].ans=k[d].ans+1;
			}
		}
		if(getnm(t,u)>0){
			if(vis[t-pow[u]][u]==0){
				h++;h%=inf;
				k[h].num=t-pow[u];
				k[h].gb=u;	
				k[h].ans=k[d].ans+1;
			}
		}
		if(u>1){
			if(vis[change(1,u,t)][u]==0){
				h++;h%=inf;
				k[h].num=change(1,u,t);
				k[h].gb=u;	
				k[h].ans=k[d].ans+1;
			}
			if(vis[t][u-1]==0){
				h++;h%=inf;
				k[h].num=t;
				k[h].gb=u-1;	
				k[h].ans=k[d].ans+1;
			}
		}
		if(u<6){
			if(vis[change(6,u,t)][u]==0){
				h++;h%=inf;
				k[h].num=change(6,u,t);
				k[h].gb=u;	
				k[h].ans=k[d].ans+1;
			}
			if(vis[t][u+1]==0){
				h++;h%=inf;
				k[h].num=t;
				k[h].gb=u+1;	
				k[h].ans=k[d].ans+1;
			}
		}
		d++;
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
