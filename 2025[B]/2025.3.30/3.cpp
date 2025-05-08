#include<bits/stdc++.h>
#define int long long
using namespace std;
int N,x,k1,k2,k;
int i;
deque<int>q;
char c[1009];
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>N;
	for(i=1;i<=N;i++){
		scanf("%lld",&x);
		q.push_back(x);
	}
	for(i=1;i<N;i++){
		getchar();
		c[i]=getchar();
	}
	for(i=N-1;i>=1;i--){
		k1=q.back();q.pop_back();
		k2=q.back();q.pop_back();
		if(c[i]=='*')k=k2*k1;
		else if(c[i]=='-')k=k2-k1;
		else if(c[i]=='+')k=k2+k1;
		else{
			if(k1==0){
				i=-1;
				printf("ERROR: %lld/0\n",k2);
				break;
			}
			else k=k2/k1;
		}
		q.push_back(k);
	}
	if(i!=-1){
		k=q.back();
		printf("%lld\n",k);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
