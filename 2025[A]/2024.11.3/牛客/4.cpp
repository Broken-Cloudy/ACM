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
	    // �ҵ��ܴﵽĿ�� MEX �� y ֵ�ķ�Χ
	    vector<int>kk;
	    for (int y=0; y<=k;++y) {
	        if(work(x+y)==ans) {
	            kk.push_back(y);
	        }
	    }
	    // ��������λ MEX ����Ч y ������
	    cout<<work(x)<<" "<<kk.size()<<endl;
	}
	fclose(stdin);fclose(stdout);
    return 0;
}

