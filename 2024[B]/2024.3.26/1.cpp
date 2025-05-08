#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,a[100009],i,cnt,l,r,t;
int dir[100009],len[100009];
int lian[100009];
map<int,int>m;
bool f;
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++){//0为结束点 
		if(!m.count(a[i])){
			m[a[i]]=i;//m[a[i]]保存当前i储存位置 
		}
		else{
			//m[a[i]]储存位置 
			t=m[a[i]];//上一个 
			lian[t]=i;
			m[a[i]]=i;//m[a[i]]保存当前i储存位置 
		}
	}
	for(i=1;i<=n;i++){
		t=lian[i];
		if(t==0)continue;//找不到下一个 
		else{
			if(t==i+1){//下一个相邻，不合法
				t=lian[t];//再找一个 
				if(t==0)continue;//找不到下一个 
				else{//找到了 
					cnt++;
					dir[cnt]=i;
					len[cnt]=t-i+1;
				}
			}
			else{//下一个不相邻，合法
				cnt++;
				dir[cnt]=i;
				len[cnt]=t-i+1;
			}
		}
	}
	for(i=1;i<=q;i++){
		scanf("%lld%lld",&l,&r);
		if(r-l+1<=2){
			printf("NO\n");
			continue;
		}
		f=0;
		int d=lower_bound(dir+1,dir+1+cnt,l)-(dir);
		while(dir[d]<r&&d<=cnt){
			if(dir[d]+len[d]-1<=r){
				printf("YES\n");
				f=1;
				break;
			}
			d++;
		}
		if(f==0){
			printf("NO\n");
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
