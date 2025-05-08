#include<bits/stdc++.h>
#define int long long
using namespace std;
int i,j,n,a[200009],ANS,b[21],vis[21],bh,dian[200009][21];
int now[21][200009];
int check(){//O(4*10^5)
/*
	int i,j=1,ans=0,now[21],num[21];
	memset(now,0,sizeof(now));memcpy(num,vis,sizeof(vis));
	for(i=1;i<=n;i++){
		if(num[b[j]]>0){
			now[b[j]]+=i;
			num[b[j]]--;
		}
		else j++;
	}
	for(i=1;i<=20;i++){
		ans+=abs(now[i]-dian[i]);
	}
	return ans;
	*/
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(!vis[a[i]]){
			b[++b[0]]=a[i];
		}
		vis[a[i]]++;
		for(j=1;j<=20;j++)dian[i][j]=dian[i-1][j];
		dian[i][a[i]]++;
		now[a[i]][++now[a[i]][0]]=i;
	}
	ANS=check();
	for(i=1;i<=b[0];i++){//O(20)
		bh=0;
		for(j=1;j<=i;j++){//O(20)
			//插入到第b[j]个数 
			
		}
		if(bh){
			swap(b[i],b[bh]);
		}
	}
	cout<<ANS<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
