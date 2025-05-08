#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a,b,c,d;
int p[59],vis[59];
bool f=0;
void dfs(int x,int r,int num){
	int i;
	if(f==1)return;
	if(x==3){
		if(r>6)return;
		if(num==3){
			int ans1=0,ans2=0;
			for(i=1;i<=6;i++){
				if(vis[i]==1)ans1+=p[i]*p[i];
				else ans2+=p[i]*p[i];
			}
			if(ans1==ans2){
				f=1;
				for(i=1;i<=6;i++){
					if(vis[i]==1)printf("%lld\n",p[i]);
				}
			}
			return;
		}
		vis[r]=1;
		dfs(3,r+1,num+1);
		vis[r]=0;
		dfs(3,r+1,num);
	}
	else{
		if(r>24)return;
		if(num==12){
			int ans1=0,ans2=0;
			for(i=1;i<=24;i++){
				if(vis[i]==1)ans1+=p[i]*p[i];
				else ans2+=p[i]*p[i];
			}
			if(ans1==ans2){
				f=1;
				for(i=1;i<=24;i++){
					if(vis[i]==1)printf("%lld\n",p[i]);
				}
			}
			return;
		}
		vis[r]=1;
		dfs(4,r+1,num+1);
		vis[r]=0;
		dfs(4,r+1,num);
	}
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n;
	if(n==3){
		cin>>a>>b>>c;
		p[1]=a*100+b*10+c;p[2]=a*100+c*10+b;p[3]=b*100+a*10+c;
		p[4]=b*100+c*10+a;p[5]=c*100+a*10+b;p[6]=c*100+b*10+a;
		dfs(3,1,0);
	}
	else{
		cin>>a>>b>>c>>d;
		p[1]=a*1000+b*100+c*10+d;p[2]=a*1000+b*100+d*10+c;
		p[3]=a*1000+c*100+b*10+d;p[4]=a*1000+c*100+d*10+b;
		p[5]=a*1000+d*100+b*10+c;p[6]=a*1000+d*100+c*10+b;
		p[7]=b*1000+a*100+c*10+d;p[8]=b*1000+a*100+d*10+c;
		p[9]=b*1000+c*100+a*10+d;p[10]=b*1000+c*100+d*10+a;
		p[11]=b*1000+d*100+a*10+c;p[12]=b*1000+d*100+c*10+a;
		p[13]=c*1000+a*100+b*10+d;p[14]=c*1000+a*100+d*10+b;
		p[15]=c*1000+b*100+a*10+d;p[16]=c*1000+b*100+d*10+a;
		p[17]=c*1000+d*100+a*10+b;p[18]=c*1000+d*100+b*10+a;
		p[19]=d*1000+a*100+b*10+c;p[20]=d*1000+a*100+c*10+b;
		p[21]=d*1000+b*100+a*10+c;p[22]=d*1000+b*100+c*10+a;
		p[23]=d*1000+c*100+a*10+b;p[24]=d*1000+c*100+b*10+a;
		dfs(4,1,0);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
