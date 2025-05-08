#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
struct nod{
	int bh,c1,c2,c3;
}; 
int i,n;
string s[10009];
nod a[10009];
double avg(nod a[]){
	double ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i].c1;
	}
	ans/=n;
	return ans;
}
signed main(){
	cin>>n;
	for(i=1;i<=n;i++){
		cout<<"输入第"<<i<<"位同学的姓名："<<endl;
		cin>>s[i];
		cout<<"输入第"<<i<<"位同学的第一门成绩："<<endl;
		cin>>a[i].c1;
		cout<<"输入第"<<i<<"位同学的第二门成绩："<<endl;
		cin>>a[i].c2;
		cout<<"输入第"<<i<<"位同学的第三门成绩："<<endl;
		cin>>a[i].c3;
	}
	double ans=avg(a);
	cout<<"第一门课的平均成绩为："<<ans<<endl;
	return 0;
}
