#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,i,a;
struct nod{
	int matrix[3][3];
};
nod A;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>a;
	A.matrix[1][1]=a;
	A.matrix[1][2]=1;
	A.matrix[1][3]=i-1;
	A.matrix[1][4]=0;
	fclose(stdin);fclose(stdout);
	return 0;
}

