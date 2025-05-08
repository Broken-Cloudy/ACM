#include<bits/stdc++.h>
using namespace std;
int anss,i;
vector<int>com(const string &s) {
    int n=s.length();
    vector<int>pi(n,0);
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        while(j>0&&s[i]!=s[j]){
            j=pi[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        pi[i]=j;
    }
    return pi;
}
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
    string s;
    cin>>s;
    vector<int>pi=com(s);
    int n=s.length();
    int l=pi[n-1];
    anss=9999999LL;
    for(i=0;i<n;i++){
		anss=min(anss,n-((i+1)-pi[i]-1));
	}
	cout<<anss<<endl;
    fclose(stdin);fclose(stdout);
    return 0;
}
