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
		cout<<"�����"<<i<<"λͬѧ��������"<<endl;
		cin>>s[i];
		cout<<"�����"<<i<<"λͬѧ�ĵ�һ�ųɼ���"<<endl;
		cin>>a[i].c1;
		cout<<"�����"<<i<<"λͬѧ�ĵڶ��ųɼ���"<<endl;
		cin>>a[i].c2;
		cout<<"�����"<<i<<"λͬѧ�ĵ����ųɼ���"<<endl;
		cin>>a[i].c3;
	}
	double ans=avg(a);
	cout<<"��һ�ſε�ƽ���ɼ�Ϊ��"<<ans<<endl;
	return 0;
}
