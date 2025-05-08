#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,i,len,j,cnt,m;
string s,a[100009],b[100009],r[100009],ss;
signed main(){
	//freopen("8.in","r",stdin);freopen("8.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>k;getchar();
		r[i]=k;
		if(k==1){
			getline(cin,s);
			len=s.length();
			b[i]+=s[0];
			for(j=0;j<len;j++){
				if(s[j]==' '){
					b[i]+=s[j+1];
				}
			}
			a[i]=s;
		}
		else{
			getline(cin,s);
			len=s.length();
			for(j=0;j<len;j++){
				if(s[j]==' '){
					b[i]+=s[j+1];
				}
			}
			a[i]=s;
		}
	}
	cin>>m;getchar();
	for(i=1;i<=m;i++){
		string name1,name2;
		getline(cin,name1);
		getline(cin,name2);
		getline(cin,s);
		len=name1.length();
		ss+=name1[0];
		for(j=0;j<len;j++){
			if(name1[j]==' '){
				ss+=name1[j+1];
			}
		}
		len=name2.length();
		ss+=name2[0];
		for(j=0;j<len;j++){
			if(name2[j]==' '){
				ss+=name2[j+1];
			}
		}
		bool f=0;
		for(j=1;j<=n;j++){
			if(ss==b[i]){
				f=1;
				cout<<b[i]<<endl;
				break;
			}
		}
		if(f==0)cout<<"tian ji bu ke xie lu"<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
