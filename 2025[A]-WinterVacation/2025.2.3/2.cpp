#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
struct nod{
	int a,b,c;
};
struct cmp{
	bool operator()(nod x,nod y){
		return x.a<y.a;
	}
};
priority_queue<nod,vector<nod>,cmp>q;
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	
	fclose(stdin);fclose(stdout);
	return 0;
}
