#include<bits/stdc++.h>
using namespace std;
int T,n,m,i,st,ci,j,s[7],pow_10[9];
int ji[100009],ou[100009],ans[100009];
queue<int>qji,qou;
void add(int st,int n,int type,int l,int r){
	int i,ans;
	for(i=n;i>=1;i--){//n
		s[i]=st%10;
		st/=10;
	}
	if(type==1){//type==1现在是处理奇数
		ans=0;
		for(i=l;i<=r;i++){
			s[i]++;s[i]=(s[i]+10)%10;
		}
		for(i=1;i<=n;i++)ans=ans*10+s[i];
		if(ji[ans]==1000000009){
			qji.push(ans);
		}
		ans=0;
		for(i=l;i<=r;i++){
			s[i]-=2;s[i]=(s[i]+10)%10;
		}
		for(i=1;i<=n;i++)ans=ans*10+s[i];
		if(ji[ans]==1000000009){
			qji.push(ans);
		}
	} 
	else{
		ans=0;
		for(i=l;i<=r;i++){
			s[i]++;s[i]=(s[i]+10)%10;
		}
		for(i=1;i<=n;i++)ans=ans*10+s[i];
		if(ou[ans]==1000000009){
			qou.push(ans);
		}
		ans=0;
		for(i=l;i<=r;i++){
			s[i]-=2;s[i]=(s[i]+10)%10;
		}
		for(i=1;i<=n;i++)ans=ans*10+s[i];
		if(ou[ans]==1000000009){
			qou.push(ans);
		}
	}
}
int s1[7],s2[7];
int doit(int x,int y){
	int ans=0,i;
	for(i=n;i>=1;i--){//n
		s1[i]=x%10;
		x/=10;
	}
	for(i=n;i>=1;i--){//n
		s2[i]=y%10;
		y/=10;
	}
	for(i=1;i<=n;i++){
		s1[i]+=s2[i];
		s1[i]=(s1[i]+10)%10;
	}
	for(i=1;i<=n;i++)ans=ans*10+s1[i];
	return ans;
}
void work(int n,int r){
	int i,j;
	if(r%2==1){
		while(!qou.empty()){//ou-->ji
			int t=qou.front();qou.pop();
			if(ou[t]<1000000009)continue;
			else ou[t]=r-1;
			for(i=1;i<=n;i++){//n^2*10^n
				for(j=i;j<=n;j++){
					add(t,n,1,i,j);
				}
			}
		}
	}
	else{
		while(!qji.empty()){//ji-->ou
			int t=qji.front();qji.pop();
			if(ji[t]<1000000009)continue;
			else ji[t]=r-1;
			for(i=1;i<=n;i++){//n2
				for(j=i;j<=n;j++){
					add(t,n,0,i,j);
				}
			}
		}
	}
}
int ANS;
void putout(int x){
	int i;
	for(i=n;i>=1;i--){//n
		s[i]=x%10;
		x/=10;
	}
	for(i=1;i<=n;i++){//n
		printf("%d",s[i]);
	}
	putchar('\n');
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;pow_10[0]=1;
	for(i=1;i<=7;i++)pow_10[i]=pow_10[i-1]*10;
	while(T--){
		scanf("%d%d",&n,&m);ANS=-1;
		for(i=0;i<=pow_10[n]-1;i++){
			ji[i]=ou[i]=1000000009;
		}
		i=1;qou.push(0);
		while(i<=50){
			work(n,i);
			i++;
		}
		for(i=0;i<=pow_10[n]-1;i++){
			ans[i]=0;
		}
		for(int o=1;o<=m;o++){//m
			scanf("%d%d",&st,&ci);
			for(i=0;i<=pow_10[n]-1;i++){//10^n
				int t=doit(i,st);
				if(ji[i]<=ci&&abs(ci-ji[i])%2==0||ou[i]<=ci&&abs(ci-ou[i])%2==0){
					ans[t]++;
				}
			}
		}
		for(i=0;i<=pow_10[n]-1;i++){//10^n
			if(ans[i]==m&&ANS==-1){
				ANS=i;
			}
			else if(ans[i]==m){
				ANS=1000000009;
			}
		}
		if(ANS==-1)printf("IMPOSSIBLE\n");
		else if(ANS==1000000009)printf("MANY\n");
		else putout(ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
