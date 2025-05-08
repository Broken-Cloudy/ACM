#include<bits/stdc++.h>
#define int long long
using namespace std;
char c;
int ans,k,kk;
bool f,ff,fff;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	while(c!=-1){
		c=getchar();
		if(c>='a'&&c<='z'){
			f=1;kk++;
		}
		else if(c>='A'&&c<='Z'){
			ff=1;kk++;
		}
		else if(c>='0'&&c<='9'){
			fff=1;kk++;
		}
		else{
			if(f==1&&ff==1&&fff==1){
				ans+=5;
			}
			else if((f==1&&fff==1)||(ff==1&&fff==1)){
				ans+=3;
			}
			else if(f==1&&ff==1)ans+=1;
			if(f==1||ff==1||fff==1)k++;
			f=0;ff=0;fff=0;
		}
	}
	printf("%lld\n",ans);
	printf("%lld %lld\n",kk,k);
	fclose(stdin);fclose(stdout);
	return 0;
}
