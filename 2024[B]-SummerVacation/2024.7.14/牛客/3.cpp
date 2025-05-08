#include<bits/stdc++.h>
#define int long long
using namespace std;
double x,y,t,a,b,c;
double cur,need,mi,ti;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>x>>y>>t>>a>>b>>c;
	cur=x;
    if(cur<=t){
        need=100-cur;
        ti=need/c;
        mi=ti;
    } 
	else{
        need=100-cur;
        ti=need/b;
        mi=ti;
        
        need=100-t;
        ti=need/c;
        ti+=(x-t)/y;
        mi=min(mi,ti);
    }
    printf("%.6lf\n",mi);
	fclose(stdin);fclose(stdout);
	return 0;
}
