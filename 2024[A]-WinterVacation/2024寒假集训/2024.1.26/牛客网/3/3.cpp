#include<bits/stdc++.h>
using namespace std;
int t;
int T,n,p,a[100010],zuo,you,i,j;
int main(){
	freopen("3.in","r",stdin);freopen("3.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		scanf("%d%d",&n,&p);
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		i=p;j=p;
		if(a[p]<9){
			printf("0 0\n");
		}
		else{
			t=0;
			zuo=you=0;
			zuo++;you++;a[p]=0;
			if(i>0)i--;if(j<=n)j++;
			while(i>0||j<=n){
				t++;
				if(t>n+1)break;
				if(zuo==0&&you==0)break;
				if(i>0){
					if(a[i]==9&&zuo>0){
						zuo--;
						a[i]=0;
						i--;
						zuo++;you++;
					}
					else{
						if(zuo>0){
							a[i]++;
							zuo--;
						}	
					}
				}
				if(j<=n){
					if(a[j]==9&&you>0){
						you--;
						a[j]=0;
						j++;
						zuo++;you++;
					}
					else{
						if(you>0){
							a[j]++;
							you--;
						}
					}
				}
			}
			printf("%d %d\n",zuo,you);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
