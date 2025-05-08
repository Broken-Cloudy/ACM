#include<bits/stdc++.h>
using namespace std;
int T,i,ans,a,b,c;
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		ans=0;
		scanf("%d%d%d",&a,&b,&c);
		if(a==100)ans+=0;
		else if(a==150)ans+=1;
		else ans+=2;
		if(b==29||b==30||b==31||b==32)ans+=0;
		else if(b==34||b==36||b==38||b==40)ans+=1;
		else ans+=2;
		if(c==29||c==30||c==31||c==32)ans+=0;
		else if(c==34||c==36||c==38||c==40)ans+=1;
		else ans+=2;
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
