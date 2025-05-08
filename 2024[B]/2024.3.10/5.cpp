#include<bits/stdc++.h>
using namespace std;
int n,k,i,da[908],xiao[908],ans,d,s;
char c;
int main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>n>>k;
	getchar();
	for(i=1;i<=n;i++){
		c=getchar();
		if(c>='a'&&c<='z'){
			xiao[c-'a'+1]++;
		}
		else{
			da[c-'A'+1]++;
		}
	}
	for(i=1;i<=26;i++){
		d=min(da[i],xiao[i]);
		da[i]-=d;xiao[i]-=d;
		ans+=d;
		if(da[i]>=2){
			s+=da[i]/2;
		}
		else{
			s+=xiao[i]/2;
		}
	}
	ans+=min(k,s);
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
