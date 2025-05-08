#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int x,y,z;
}a[1000009];
int T,n,ans,i,vis[1000009];
void add(int x,int y,int z){
	ans++;
	a[ans].x=x;a[ans].y=y;a[ans].z=z;
	vis[x]=1;vis[y]=1;vis[z]=1;
	return;
}
void dfs(int x){
	int kk,i;
	if(x==6){
		add(2,1,4);add(3,5,6);
	}
	else if(x==9){
		add(2,5,6);add(3,1,9);add(4,7,8);
	}
	else if(x==12){
		add(2,5,6);add(3,1,9);add(4,7,8);add(10,11,12);
	}
	else if(x==15){
		add(2,5,6);add(3,1,9);add(4,7,8);add(10,13,15);add(12,11,14);
	}
	else if(x==18){
		add(2,5,6);add(3,1,9);add(4,7,8);add(10,13,15);add(12,11,14);
		add(16,17,18);
	}
	else if(x==21){
		add(2,5,6);add(3,1,9);add(4,7,8);add(10,13,15);add(12,11,14);
		add(16,17,20);add(18,19,21);
	}
	else if(x==24){
		add(2,5,6);add(3,1,9);add(4,7,8);add(10,13,15);add(12,11,14);
		add(16,17,20);add(18,19,21);add(22,23,24);
	}
	else{
		if(x%2==1){
			kk=x/2;i=x;
			if(kk%2==0){
				add(kk+1,kk+2,x);
				while(i>kk){
					if(vis[i]==0)add(i,i-1,i/2);
					i--;
				}
			}
			else{
				add(kk+1,(kk+1)/2,x);
				while(i>kk){
					if(vis[i]==0)add(i,i-1,i/2);
					i--;
				}
			}
		}
		else{
			kk=x/2;i=x;
			if(kk%2==0){
				while(i>kk){
					if(vis[i]==0)add(i,i-1,i/2);
					i--;
				}
			}
			else{//!!!!
				add(x,x-1,x-2);
			}
		}
		i=x;
		while(i>=1){
			if(vis[i]==1)i--;
			else break;
		}
		dfs(i);
	}
}
signed main(){
	freopen("7.in","r",stdin);freopen("7.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		if(n<=3){
			printf("0\n");
		}
		else if(n>=4&&n<=5){
			printf("1\n");
			printf("2 3 4\n");
		}
		else{
			n=(n/3*3);ans=0;
			for(i=1;i<=n;i++)vis[i]=0;
			dfs(n);
			printf("%lld\n",ans);
			for(i=1;i<=ans;i++){
				printf("%lld %lld %lld\n",a[i].x,a[i].y,a[i].z);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
