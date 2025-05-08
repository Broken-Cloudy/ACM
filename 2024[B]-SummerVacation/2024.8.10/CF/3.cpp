#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,i,n,k,maxx,op1,ans,b[200009],SS;
struct nod{
	int a,b;
};
nod p[200009];
bool cmp(nod x,nod y){
	if(x.b==y.b){
		return x.a>y.a;
	}
	else return x.b>y.b;
}
bool cmp2(nod x,nod y){
	return x.a<y.a;
}
bool check(int x,int op){
	int i,ops=0,cc=0;
	for(i=n;i>=1;i--){
		if(p[i].a<x&&p[i].b==0&&i>=n/2){
        	cc++;
		}
	}
	for(i=n;i>=1;i--){
		if(p[i].a<x&&p[i].b==1){ //仅对b[i]=1的位置尝试增加
            ops+=x-p[i].a;
            cc--;
			b[i]=x;
            if(cc==0)break;
        }
        else b[i]=p[i].a;
	}
	sort(b+1,b+1+n);
	if(ops>op)return false;
	else{
		if(b[n/2]<x)return false;
		else{
			SS=op-ops;
			return true;
		}
	}
}
void b_s(int l,int r,int op){
	int mid=(l+r)/2;
	if(l+1==r){
		if(check(r,op)==1){
			for(i=n;i>=1;i--){
				if(p[i].b==1){ //仅对b[i]=1的位置尝试增加
					ans=max(ans,p[i].a+SS+r);
        		    break;
        		}
			}
		}
		else{
			check(l,op);
			for(i=n;i>=1;i--){
				if(p[i].b==1){ //仅对b[i]=1的位置尝试增加
					ans=max(ans,p[i].a+SS+l);
        		    break;
        		}
			}
		}
		return;
	}
	else if(l==r){
		for(i=n;i>=1;i--){
			if(p[i].b==1){ //仅对b[i]=1的位置尝试增加
				ans=max(ans,p[i].a+SS+r);
        	    break;
        	}
		}
		return;
	}
	if(check(mid,op)==1){
		for(i=n;i>=1;i--){
			if(p[i].b==1){ //仅对b[i]=1的位置尝试增加
				ans=max(ans,p[i].a+SS+mid);
        	    break;
        	}
		}
		b_s(mid,r,op);
	}
	else{
		b_s(l,mid,op);
	}
}
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);maxx=0;
		for(i=1;i<=n;i++)scanf("%lld",&p[i].a),maxx=max(maxx,p[i].a);
		for(i=1;i<=n;i++)scanf("%lld",&p[i].b);
		sort(p+1,p+1+n,cmp);
		for(i=1;i<=n;i++){
			if(p[i].b==1)op1=i;
			else{op1=i-1;break;}
		}
		if(op1==0){
			sort(p+1,p+1+n,cmp2);
			ans=p[n].a+p[n/2].a;
			printf("%lld\n",ans);
			continue;
		}
		else{
			sort(p+1,p+1+n,cmp2);
			ans=p[n].a+p[n/2].a;
			b_s(1,maxx+k,k);
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
