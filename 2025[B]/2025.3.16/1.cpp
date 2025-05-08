#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,x1,x2,x3,x4,X,ans,i,j,Y;
void dfs(int st,int L,int R){
	int y;
	if(L+1==R){
		ans=R;
	}
	else{
		int mid=(L+R)/2;
		printf("? %lld %lld\n",st,st+mid-1);fflush(stdout);
		scanf("%lld",&y);
		if(y==1)dfs(st,L,mid);
		else dfs(st,mid,R);
	}
}
void D1(int st,int L,int R){
	int y;
	if(L+1==R){
		ans=R;
	}
	else{
		int mid=(L+R)/2;
		printf("? %lld %lld\n",st,st+mid-1);fflush(stdout);
		scanf("%lld",&y);
		if(y==0)D1(st,L,mid);
		else D1(st,mid,R);
	}
}
void D2(int ed,int L,int R){
	int y;
	if(L+1==R){
		ans=R;
	}
	else{
		int mid=(L+R)/2;
		printf("? %lld %lld\n",ed-mid+1,ed);fflush(stdout);
		scanf("%lld",&y);
		if(y==0)D2(ed,L,mid);
		else D2(ed,mid,R);
	}
}
signed main(){
//	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		printf("? %lld %lld\n",1LL,(n>>2LL));fflush(stdout);
		scanf("%lld",&x1);
		printf("? %lld %lld\n",(n>>2LL)+1,(n>>1LL));fflush(stdout);
		scanf("%lld",&x2);
		printf("? %lld %lld\n",(n>>1LL)+1,(n>>2LL)+(n>>1LL));fflush(stdout);
		scanf("%lld",&x3);
		if(x1==0&&x2==0&&x3==0)x4=1;
		else if(x1==1&&x2==1&&x3==0)x4=1;
		else if(x1==1&&x2==0&&x3==1)x4=1;
		else if(x1==0&&x2==1&&x3==1)x4=1;
		else x4=0;
		X=x1+x2+x3+x4;
		if(X==3){//>=k
			if(x1==1)dfs(1,1,(n>>2LL));
			else dfs((n>>2LL)+1,1,(n>>2LL));
			printf("! %lld\n",ans);fflush(stdout);
		}
		else{//<k(剩余30次)
			if(x1==1)D1(1,(n>>2LL),n-1);
			else if(x2==1){
				printf("? %lld %lld\n",(n>>2LL)+1,(n>>2LL)+(n>>1LL));fflush(stdout);
				scanf("%lld",&Y);
				if(Y==0){//本应该是1 
					D1((n>>2LL)+1,(n>>2LL),(n>>1LL));
				}
				else{
					D1(1,(n>>1LL),n-1);
				}
			}
			else if(x3==1){
				printf("? %lld %lld\n",(n>>2LL)+1,(n>>2LL)+(n>>1LL));fflush(stdout);
				scanf("%lld",&Y);
				if(Y==0){//本应该是1 
					D2((n>>2LL)+(n>>1LL),(n>>2LL),(n>>1LL));
				}
				else{
					D2(n,(n>>1LL),n-1);
				}
			}
			else D2(n,(n>>2LL),n-1);
			printf("! %lld\n",ans);fflush(stdout);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
