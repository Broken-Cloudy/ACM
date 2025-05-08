#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,T,x1,x2,y,ans[100009],ANS,i;
struct nod{
	int x1,x2,y;
}p[200009],t;
struct cmp{
	bool operator()(nod x,nod y){
		return x.y>y.y;
	}
};
priority_queue<nod,vector<nod>,cmp>q,Q;
char c;
map<int,map<int,int>>M;
signed main(){
	freopen("8.in","r",stdin);freopen("8.out","w",stdout);
	cin>>n>>T;
	while(T--){
		getchar();scanf("%c %lld %lld %lld",&c,&x1,&x2,&y);
		if(c=='+'){
			M[x1][x2]=1;
			t.x1=x1;t.x2=x2;t.y=y;
			q.push(t);
		}
		else{
			M[x1][x2]=0;
		}
		for(i=1;i<=n;i++)ans[i]=i;
		while(!q.empty()){
			t=q.top();q.pop();
			if(M[t.x1][t.x2]==1){
				Q.push(t);
				swap(ans[t.x1],ans[t.x2]);
			}
		}
		ANS=0;
		for(i=1;i<=n;i++){
			ANS+=i*ans[i];
		}
		printf("%lld\n",ANS);
		while(!Q.empty()){
			t=Q.top();Q.pop();
			q.push(t);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
