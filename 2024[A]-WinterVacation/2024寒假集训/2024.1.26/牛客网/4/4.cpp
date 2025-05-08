#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll T,x,y,G,lc,t[309],a1[309],a2[309],a3[309],cnt,i,tt;
void gcd(ll a,ll b){
	if(b==0){
		G=a;
		return;
	}
	gcd(b,a%b);
}
int main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;
	for(ll o=1;o<=T;o++){
		cnt=0;
		scanf("%llu%llu",&x,&y);
		if(x<y)swap(x,y);
		gcd(x,y);x/=G;y/=G;
		t[0]=1;tt=0;t[1]=1;tt=1;
		cnt++;a1[1]=1;a2[1]=x*G;a3[1]=y*G;
		cnt++;a1[2]=1;a2[2]=x*G;a3[2]=y*G;
		lc=x;lc*=y;
		while(t[tt]*2<=lc){
			cnt++;
			a1[cnt]=2;a2[cnt]=t[tt]*G;a3[cnt]=t[tt]*G;
			cnt++;
			a1[cnt]=2;a2[cnt]=t[tt]*G;a3[cnt]=t[tt]*G;
			t[tt+1]=t[tt-1]*2;
			tt++;
			t[tt+1]=t[tt-1]*2;
			tt++;
		}
		if(t[tt]==lc){
			printf("%llu\n",cnt);
			for(i=1;i<=cnt;i++){
				printf("%llu %llu %llu\n",a1[i],a2[i],a3[i]);
			}
			cnt=0;
		}
		else{
			ll res=t[tt-2];
			while(res<lc){
				ll d=upper_bound(t,t+tt+1,lc-res)-t-1;
				cnt++;
				a1[cnt]=1;a2[cnt]=res*G;a3[cnt]=t[d]*G;
				res+=t[d];
			}
			printf("%llu\n",cnt);
			for(i=1;i<=cnt;i++){
				printf("%llu %llu %llu\n",a1[i],a2[i],a3[i]);
			}
			cnt=0;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
