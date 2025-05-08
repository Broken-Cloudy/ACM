#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int bigger,smaller,equal;
};
nod h[200009];
int T,n,i,j,cnt,a[200009],ans,k,sum,zero,Z,ANS,num[200009];
int SS;
bool check(int x,int k){
	int kk=k-num[x];
	if(kk>=h[x].smaller+h[x].equal)return 0;
	else return 1;
}
void b_search(int l,int r,int k){
	if(r<l){
		SS=0;
		return;
	}
	if(l==r){
		SS=l;
		return;
	}
	else if(l+1==r){
		if(check(l,k)==1)SS=l;
		else SS=r;//大 
		return;
	}
	else{
		int mid=(l+r)/2;
		if(check(mid,k)==1){
			b_search(l,mid,k);
		}
		else{
			b_search(mid,r,k);
		}
	}
}
bool check2(int x,int k){
	int kk=num[x]-k;
	if(kk>=h[x].bigger+h[x].equal)return 0;
	else return 1;
}
void b_search2(int l,int r,int k){
	if(r<l){
		SS=0;
		return;
	}
	if(l==r){
		SS=l;
		return;
	}
	else if(l+1==r){
		if(check2(l,k)==0)SS=l;
		else SS=r;//大 
		return;
	}
	else{
		int mid=(l+r)/2;
		if(check2(mid,k)==0){
			b_search2(l,mid,k);
		}
		else{
			b_search2(mid,r,k);
		}
	}
}
signed main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	cin>>T;
	while(T--){
		for(i=1;i<=cnt;i++){
			num[i]=0;
			h[i].bigger=0;h[i].equal=0;h[i].smaller=0;
		}
		scanf("%lld",&n);cnt=0;ans=0;Z=0;
		for(i=100000-n;i<=100000+n;i++)a[i]=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&k);
			k+=100000;
			a[k]++;
			if(k>=100000)Z++;
		}
		sum=0;
		for(i=100000-n;i<=100000+n;i++){
			if(i==100000){
				cnt++;
				zero=cnt;
				num[cnt]=i;
				h[cnt].equal=a[i];
				h[cnt].smaller=sum;
				h[cnt].bigger=n-a[i]-sum;
				sum+=a[i];
			}
			else if(a[i]>0){
				if(i>100000){//正数 
					cnt++;
					num[cnt]=i;
					h[cnt].equal=a[i];
					h[cnt].smaller=sum-h[zero].smaller-h[zero].equal;//只要大于零的数 
					h[cnt].bigger=n-a[i]-sum;
					sum+=a[i];
				}
				else{//负数
					cnt++;
					num[cnt]=i;
					h[cnt].equal=a[i];
					h[cnt].smaller=sum-h[zero].smaller;//只要大于零的数 
					h[cnt].bigger=n-a[i]-sum-Z;
					sum+=a[i];
				}
			}
		}
		ANS=h[zero].equal;
		for(i=zero+1;i<=cnt;i++){
			int r=num[i]-100000;//需要拉升的距离
			if(r>h[i].equal+h[i].bigger)break;
			ans=min(h[zero].equal+h[i].equal+h[i].bigger+h[i].smaller-r,h[zero].equal+h[i].equal+h[i].smaller); 
			b_search(1,zero-1,num[i]);
			if(SS==0){
				ANS=max(ANS,ans);
				continue;
			}
			int kk=num[i]-num[SS];
			if(kk>h[SS].equal+h[SS].smaller)continue;
			ans+=min(h[SS].equal+h[SS].bigger,h[SS].equal+h[SS].smaller+h[SS].bigger-kk);
			ANS=max(ANS,ans);
		}
		for(i=zero-1;i>=1;i--){
			int r=100000-num[i];//需要下降的距离
			if(r>h[i].equal+h[i].smaller)break;
			ans=min(h[zero].equal+h[i].equal+h[i].bigger+h[i].smaller-r,h[zero].equal+h[i].equal+h[i].bigger); 
			b_search2(zero+1,cnt,num[i]);
			if(SS==0){
				ANS=max(ANS,ans);
				continue;
			}
			int kk=num[SS]-num[i];
			if(kk>h[SS].equal+h[SS].bigger)continue;
			ans+=min(h[SS].equal+h[SS].smaller,h[SS].equal+h[SS].smaller+h[SS].bigger-kk);
			ANS=max(ANS,ans);
		}
		printf("%lld\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
