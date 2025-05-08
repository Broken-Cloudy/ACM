#include<bits/stdc++.h>
using namespace std;
long long x,i,ans[3500008],anss,j,t;//标记质数 
long long b[12000],a[12000],m[3500008],cnt,shu,r,k;
bool flag[3500008];//0是质数，1不是质数 
bool f;
int main(){
	freopen("5.in","r",stdin);freopen("5.out","w",stdout);
	cin>>x;flag[1]=1; 
	for(i=2;i<=3500000;i++){
		if(flag[i]==0){
			ans[++anss]=i;//记录下来 
		}
		for(j=1;j<=anss&&i*ans[j]<=3500000;j++){
			flag[ans[j]*i]=1;//一下子筛到底 
			//当然，i肯定比ans[j]大，因为ans[j]是在i之前得出的
			if(i%ans[j]==0)break;
		}
	}
	while(x!=1){
		for(i=1;i<=anss;i++){
			if(x%ans[i]==0){
				a[++cnt]=ans[i];
				x/=ans[i];
				break;
			}
		}
		if(i==anss+1){
			a[++cnt]=x;
			break;
		}
	}
	int maxans=0,bh;
	for(i=1;i<=cnt;i++)if(a[i]<=3500000)m[a[i]]++;
	while(k<cnt){
		if(f==1)break;
		for(i=1;ans[i]<=3490000;i++){
		if(m[ans[i]]>0){
			if(b[k]!=ans[i])b[++k]=ans[i];
			else{
				for(j=k;j>=1;j--){
					if(ans[i]!=b[j]&&ans[i]!=b[j-1]){
						for(int o=k;o>=j;o--){
							long long t=b[o+1];
							b[o+1]=b[o];
							b[o]=t;
						}
						b[j]=ans[i];
						k++;
						break;
					}
				}
				if(j==0){
					f=1;break;
				}
			}
			m[ans[i]]--;
		}
	}
	if(i==249483)break;
	}
	if(k<cnt)b[++k]=a[cnt];
	for(i=2;i<=k;i++)if(b[i]==b[i-1])f=1;
	if(f==1){
		cout<<-1<<endl;
	}	
	else{
		printf("%lld\n",k);
		for(i=1;i<=k;i++){
			if(i!=k)printf("%lld ",b[i]);
			else printf("%lld\n",b[i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
