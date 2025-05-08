#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T;
int work(int x) {
    set<int>di;
    while(x>0){
        di.insert(x%10);
        x/=10;
    }
    int mex=0;
    while(di.count(mex)){
        mex++;
    }
    return mex;
}
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
    int x,k;
    cin>>T;
    while(T--){
    	cin>>x>>k;
	    int ans=work(x)+1;
	    // 找到能达到目标 MEX 的 y 值的范围
	    vector<int>kk;
	    for (int y=0; y<=k;++y) {
	        if(work(x+y)==ans) {
	            kk.push_back(y);
	        }
	    }
	    // 输出最大数位 MEX 和有效 y 的数量
	    cout<<work(x)<<" "<<kk.size()<<endl;
	}
	fclose(stdin);fclose(stdout);
    return 0;
}

