#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int k1,k2;
struct nod{
	int bh,num;
};
struct cmp{
	bool operator()(nod x,nod y){
		return x.num<y.num;//Æ«ÏòÓÚÅÅÐò 
	}
};
set<nod,cmp>a;
set<nod,cmp>::iterator it;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	while(~scanf("%d%d",&k1,&k2)){
		nod r;
		r.bh=k1;
		r.num=k2;
		a.insert(r);
	}
	for(it=a.begin();it!=a.end();it++){
		nod r=*it;
		printf("%d ",r.num);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
