#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c,ans,a1,a2,b1,b2,T,i,f;
bool ff,fff;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
    cin>>T;
    for(int o=1;o<=T;o++){
    	ff=0;fff=0;
    	scanf("%lld%lld%lld",&a,&b,&c);
    	if(a<0){
    		fff=1;
    		a=-a;b=-b;c=-c;
		}
    	for(a1=a;a1>=-a;a1--){
    		if(ff==1){
    			a1++;
    			break;
    		}
    		if(a1==0)continue;
    		if(a%max(a1,-a1)==0){
    			a2=a/a1;
    			f=sqrt(b*b-4*a1*a2*c);
    			if((b*b-4*a1*a2*c)>0&&(b*b-4*a1*a2*c)%f==0){
    				if((b+f)%(2*a2)==0){
						b1=(b+f)/(2*a2);
						if((b-a2*b1)%a1==0){
							b2=(b-a2*b1)/a1;
							ff=1;
						}
						else{
							ff=0;
						}
					}
					else if((b-f)%(2*a2)==0){
						b1=(b-f)/(2*a2);
						if((b-a2*b1)%a1==0){
							b2=(b-a2*b1)/a1;
							ff=1;
						}
						else{
							ff=0;
						}
					}
					else{
						ff=0;
					}
				}
				else if(b*b-4*a1*a2*c==0){
					if(b%(2*a2)==0){
						b1=b/(2*a2);
						if((b-a2*b1)%a1==0){
							b2=(b-a2*b1)/a1;
							ff=1;
						}
						else{
							ff=0;
						}
					}
					else{
						ff=0;
					}
				}
				else{
					ff=0;
				}
			}
			else ff=0;
		}
		if(ff==1){
			if(fff==0)printf("%lld %lld %lld %lld\n",a1,b1,a2,b2);
			else{
				printf("%lld %lld %lld %lld\n",-a1,-b1,a2,b2);
			}
		}
		else printf("NO\n");
	}
	fclose(stdin);fclose(stdout);
    return 0;
}
