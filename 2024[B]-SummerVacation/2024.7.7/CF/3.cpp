#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,T,j,k,x;
int a[200009],b[200009],c[200009];
int ans1,ans2,ans3,tot,R3;
int l1,l2,l3,r1,r2,r3;
bool f;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%lld",&x);tot=0;
		for(i=1;i<=x;i++)scanf("%lld",&a[i]),tot+=a[i];
		for(i=1;i<=x;i++)scanf("%lld",&b[i]);
		for(i=1;i<=x;i++)scanf("%lld",&c[i]);
		if(tot%3==0)R3=tot/3;
		else R3=tot/3+1;
		//1 2 3
		l1=1;ans1=0;ans2=0;ans3=0;
		for(i=1;i<=x;i++){
			if(ans1<R3){
				ans1+=a[i];
				if(ans1>=R3){
					r1=i;
					l2=i+1;
				}
			}
			else if(ans2<R3){
				ans2+=b[i];
				if(ans2>=R3){
					r2=i;
					l3=i+1;
				}
			}
			else if(ans3<R3){
				ans3+=c[i];
				if(ans3>=R3){
					r3=i;
					break;
				}
			}
		}
		if(ans1>=R3&&ans2>=R3&&ans3>=R3){
			printf("%lld %lld %lld %lld %lld %lld\n",l1,r1,l2,r2,l3,r3);
			continue;
		}
		//1 3 2
		l1=1;ans1=0;ans2=0;ans3=0;
		for(i=1;i<=x;i++){
			if(ans1<R3){
				ans1+=a[i];
				if(ans1>=R3){
					r1=i;
					l3=i+1;
				}
			}
			else if(ans3<R3){
				ans3+=c[i];
				if(ans3>=R3){
					r3=i;
					l2=i+1;
				}
			}
			else if(ans2<R3){
				ans2+=b[i];
				if(ans2>=R3){
					r2=i;
					break;
				}
			}
		}
		if(ans1>=R3&&ans2>=R3&&ans3>=R3){
			printf("%lld %lld %lld %lld %lld %lld\n",l1,r1,l2,r2,l3,r3);
			continue;
		}
		//2 1 3
		l2=1;ans1=0;ans2=0;ans3=0;
		for(i=1;i<=x;i++){
			if(ans2<R3){
				ans2+=b[i];
				if(ans2>=R3){
					r2=i;
					l1=i+1;
				}
			}
			else if(ans1<R3){
				ans1+=a[i];
				if(ans1>=R3){
					r1=i;
					l3=i+1;
				}
			}
			else if(ans3<R3){
				ans3+=c[i];
				if(ans3>=R3){
					r3=i;
					break;
				}
			}
		}
		if(ans1>=R3&&ans2>=R3&&ans3>=R3){
			printf("%lld %lld %lld %lld %lld %lld\n",l1,r1,l2,r2,l3,r3);
			continue;
		}
		//2 3 1
		l2=1;ans1=0;ans2=0;ans3=0;
		for(i=1;i<=x;i++){
			if(ans2<R3){
				ans2+=b[i];
				if(ans2>=R3){
					r2=i;
					l3=i+1;
				}
			}
			else if(ans3<R3){
				ans3+=c[i];
				if(ans3>=R3){
					r3=i;
					l1=i+1;
				}
			}
			else if(ans1<R3){
				ans1+=a[i];
				if(ans1>=R3){
					r1=i;
					break;
				}
			}
		}
		if(ans1>=R3&&ans2>=R3&&ans3>=R3){
			printf("%lld %lld %lld %lld %lld %lld\n",l1,r1,l2,r2,l3,r3);
			continue;
		}
		//3 1 2
		l3=1;ans1=0;ans2=0;ans3=0;
		for(i=1;i<=x;i++){
			if(ans3<R3){
				ans3+=c[i];
				if(ans3>=R3){
					r3=i;
					l1=i+1;
				}
			}
			else if(ans1<R3){
				ans1+=a[i];
				if(ans1>=R3){
					r1=i;
					l2=i+1;
				}
			}
			else if(ans2<R3){
				ans2+=b[i];
				if(ans2>=R3){
					r2=i;
					break;
				}
			}
		}
		if(ans1>=R3&&ans2>=R3&&ans3>=R3){
			printf("%lld %lld %lld %lld %lld %lld\n",l1,r1,l2,r2,l3,r3);
			continue;
		}
		//3 2 1
		l3=1;ans1=0;ans2=0;ans3=0;
		for(i=1;i<=x;i++){
			if(ans3<R3){
				ans3+=c[i];
				if(ans3>=R3){
					r3=i;
					l2=i+1;
				}
			}
			else if(ans2<R3){
				ans2+=b[i];
				if(ans2>=R3){
					r2=i;
					l1=i+1;
				}
			}
			else if(ans1<R3){
				ans1+=a[i];
				if(ans1>=R3){
					r1=i;
					break;
				}
			}
		}
		if(ans1>=R3&&ans2>=R3&&ans3>=R3){
			printf("%lld %lld %lld %lld %lld %lld\n",l1,r1,l2,r2,l3,r3);
		}
		else printf("-1\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
