#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1009][1009],i,j,v,ans,k,w,r[1000009],cnt,sum[1000009];
int aa[1000009],aacnt,cntx[1000009],cnty[1000009],vvis[1000009];
int xcnt[1000009],ycnt[1000009];
vector<vector<int> >Mx(1000009);
vector<vector<int> >My(1000009);
map<int,int>vis;
signed main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%lld",&a[i][j]);
			v=vis[a[i][j]];
			if(v==0){
				r[++cnt]=a[i][j];
				vis[a[i][j]]=cnt;
			}
			xcnt[v]++;ycnt[v]++;
		}
	}
	for(i=1;i<=n;i++){
		v=vis[a[i][j]];
		if(vvis[v]==0){
			Mx[i].reserve(xcnt[v]);
        	My[i].reserve(ycnt[v]);
        	vvis[v]=1;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			v=vis[a[i][j]];
			Mx[v].push_back(i);
            My[v].push_back(j);
		}
	}
	for(i=1;i<=cnt;i++){
		sum[0]=0;aacnt=0;
		for(j=0;j<Mx[i].size();j++){
			aa[++aacnt]=Mx[vis[r[i]]][j];
		}
		sort(aa+1,aa+1+aacnt);
		for(j=1;j<=aacnt;j++){
			sum[j]=sum[j-1]+aa[j];
		}
		for(j=1;j<=aacnt;j++){
			ans+=((aa[j]*j-sum[j])+(sum[aacnt]-sum[j-1]-aa[j]*j));
		}
		sum[0]=0;aacnt=0;
		for(j=0;j<My[i].size();j++){
			aa[++aacnt]=My[vis[r[i]]][j];
		}
		sort(aa+1,aa+1+aacnt);
		for(j=1;j<=aacnt;j++){
			sum[j]=sum[j-1]+aa[j];
		}
		for(j=1;j<=aacnt;j++){
			ans+=((aa[j]*j-sum[j])+(sum[aacnt]-sum[j-1]-aa[j]*j));
		}
	}
	printf("%lld\n",ans*2);
	fclose(stdin);fclose(stdout);
	return 0;
}
