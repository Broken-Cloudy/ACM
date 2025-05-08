#include<bits/stdc++.h>
#define int long long
using namespace std;
struct nod{
	int mini,maxx,sum,avg,num;
}t;
int T,n,i,a[200009],mini,maxx,sum,avg,num,ans;
deque<nod>q;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		sum=avg=mini=maxx=a[1];num=1;
		for(i=2;i<=n;i++){
			if(a[i]>maxx){
				t.avg=avg;t.maxx=maxx;t.mini=mini;t.sum=sum;t.num=num;
				q.push_back(t);
				sum=avg=mini=maxx=a[i];num=1;
			}
			else{
				num++;sum+=a[i];avg=sum/num;
				if(sum%num==0)maxx=mini=avg;
				else{maxx=avg+1;mini=avg;}
				while(!q.empty()){
					t=q.back();
					if(avg>t.avg)break;
					else{
						q.pop_back();
						num+=t.num;sum+=t.sum;avg=sum/num;
						if(sum%num==0)maxx=mini=avg;
						else{maxx=avg+1;mini=avg;}
					}
				}
			}
		}
		while(!q.empty()){
			t=q.back();q.pop_back();
			maxx=max(t.maxx,maxx);mini=min(t.mini,mini);
		}
		printf("%lld\n",maxx-mini);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
