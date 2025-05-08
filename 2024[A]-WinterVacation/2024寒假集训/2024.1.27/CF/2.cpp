#include<iostream>
#include<cstdio>
using namespace std;
int T,n,k,j,i,x,ans,ANS;
bool f;
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		cin>>x>>n;
		ans=x/n;
		if(x%ans==0){
			printf("%d\n",ans);
		}
		else{
			f=0;
			for(i=1;i*i<=x&&i<=ans;i++){
				if(x%i==0){
					int duo=x-(x/i)*n;
					int shao=x-i*n;
					if(shao%i==0&&shao>=0){
						ANS=i;
					}
					if(duo%(x/i)==0&&duo>=0){
						if(x/i<=ans){
							printf("%d\n",x/i);
							f=1;
							break;
						}
					}
				}
			}
			if(f==0){
				printf("%d\n",ANS);
			}
		}
		
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
