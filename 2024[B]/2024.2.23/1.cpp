#include<bits/stdc++.h>
using namespace std;
long long x,i,ans[3500008],anss,j,t;//������� 
long long a[5200][509],cnt,shu,r,k,group,b[2000009],cntt;
struct nod{
	long long bh,num;
};
nod c[3500008];
bool flag[3500008];//0��������1�������� 
bool f;
bool cmp(nod x,nod y){
	return x.num>y.num;
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>x;
	int rmb=x;
	for(i=2;i<=3500000;i++){
		if(flag[i]==0){
			ans[++anss]=i;//��¼���� 
		}
		for(j=1;j<=anss&&i*ans[j]<=3500000;j++){
			flag[ans[j]*i]=1;//һ����ɸ���� 
			//��Ȼ��i�϶���ans[j]����Ϊans[j]����i֮ǰ�ó���
			if(i%ans[j]==0)break;
		}
	}
	for(i=1;i<=anss;i++){
		while(x%ans[i]==0){
			if(ans[i]==c[group].bh){
				shu++;
				x/=ans[i];
				c[group].num++;
			}
			else{
				x/=ans[i];
				shu++;
				group++;
				c[group].bh=ans[i];
				c[group].num=1;
			}
		}
	}
	if(x!=1){
		shu++;
		group++;
		c[group].bh=x;
		c[group].num=1;
	}
	sort(c+1,c+1+group,cmp);
	int len=c[1].num;
	int number=shu;
	int nn=shu;nn-=len;
	i=0;j=1;k=1;
	if(nn<len-1||rmb==1){
		printf("-1\n");
		fclose(stdin);fclose(stdout);
		return 0;
	}
	printf("%lld\n",shu);
	while(shu>0){
		while(c[k].num>0){
			c[k].num--;shu--;i++;
			if(i>len){
				j++;i=1;
				a[j][i]=c[k].bh;
			}
			else{
				a[j][i]=c[k].bh;
			}
		}
		k++;
	}
	int deep=j;
	for(i=1;i<=len;i++){
		for(j=1;j<=deep;j++){
			if(a[j][i]!=0)printf("%lld ",a[j][i]);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
