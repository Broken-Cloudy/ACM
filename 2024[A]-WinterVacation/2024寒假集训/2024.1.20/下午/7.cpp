#include<iostream>
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
ll op,i,Q,sum,y;
struct nod{
	long long ele,tag;
};
struct cmp{
	bool operator()(nod x,nod y){
		return (x.ele+x.tag)>(y.ele+y.tag);
	}
};
int main(){
	freopen("7.in","r",stdin);freopen("7.out","w",stdout);
	priority_queue<nod,vector<nod>,cmp>q;
	cin>>Q;
	for(i=1;i<=Q;i++){
		scanf("%lld",&op);
		if(op==1){
			nod x;
			x.tag=0;
			scanf("%lld",&x.ele);
			x.tag-=sum;
			q.push(x);
		}
		else if(op==2){
			nod t=q.top();
			printf("%lld\n",t.ele+t.tag+sum);
			q.pop();
		}
		else{
			scanf("%lld",&y);
			sum+=y;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
