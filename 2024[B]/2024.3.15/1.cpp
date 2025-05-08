#include<bits/stdc++.h>
using namespace std;
long long n,i,ans,k=1;
int main(){
    //freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    cin>>n;
    ans=n*(n+1)/2;
    for(i=n;i>=1;i--){
        if(ans%i==0){
            k*=i;
            ans/=i;
        }
    }
    cout<<k<<endl;
    fclose(stdin);fclose(stdout);
    return 0;
}
