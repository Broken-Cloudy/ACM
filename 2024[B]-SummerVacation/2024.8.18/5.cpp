#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,q,j,mins[1499];
int a,b,c,d,time1,time2;
string s;
map<string,int>M;
bool f=1;
signed main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		scanf("%lld:%lld %lld:%lld",&a,&b,&c,&d);
		time1=a*60+b;time2=c*60+d;
		if(time1<=time2){
			for(j=time1;j<=time2;j++){
				mins[j]=1;
				if(j>=120)break;
			}
		}
		else{
			for(j=0;j<=time1;j++){
				mins[j]=1;
				if(j>=120)break;
			}
		}
	}
	for(i=1;i<=m;i++){
		cin>>s;
		M[s]=1;
	}
	cin>>q;
	while(q--){
		f=0;
		scanf("%lld:%lld",&a,&b);
		time1=a*60+b;
		if(time1<120&&mins[time1]==1){
			f=1;
		}
		else{
			f=0;
		}
		if(f==1){
			scanf("%lld:%lld %lld:%lld",&a,&b,&c,&d);
			time1=a*60+b;time2=c*60+d;
			if(time1>time2){
				cin>>s;
				printf("Joker xqq\n");
				continue;
			}
			else{
				cin>>s;
				if(M[s]==1){
					printf("Winner xqq\n");
				}
				else printf("Joker xqq\n");
			}
		}
		else{
			scanf("%lld:%lld %lld:%lld",&a,&b,&c,&d);
			cin>>s;
			printf("Loser xqq\n");
			continue;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
