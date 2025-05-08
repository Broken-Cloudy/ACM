#include<bits/stdc++.h>
using namespace std;
int T,n,x,y,i,a[200009],ANS,a1,a2,a3,dian,yy;
bool f=0;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		priority_queue<int,vector<int>,greater<int> >q1;//奇数
		priority_queue<int,vector<int>,greater<int> >q2;//偶数 
		ANS=0;dian=0;f=0;
		scanf("%d%d%d",&n,&x,&y);yy=y;
		for(i=1;i<=x;i++)scanf("%d",&a[i]);
		sort(a+1,a+1+x,cmp);
		a1=a[1];a2=a3=0;
		for(i=2;i<=x;i++){
			if(a2==0){
				if(a[i]==a[i-1]+1){
					dian++;
				}
				else{
					f=1;
					int bian=a[i]-a[1]+1;
					if(bian==dian+3){
						ANS+=bian-2;
					}
					else{
						ANS+=dian;
						if((bian-dian)%2==0){
							q2.push(bian-dian);
						}
						else q1.push(bian-dian);
					}
					a2=a[i];
				}
			}
			else{
				a3=a[i];
				if(a3-a2==1){
					ANS++;
				} 
				else if(a3-a2==2){
					ANS+=2;
				} 
				else{
					ANS++;
					if((a3-a2+1)%2==0){
						q2.push(a3-a2+1);
					}
					else q1.push(a3-a2+1);
				}
				a2=a3;
			}
		}
		a2=a[x];
		if((a1+n)-a2+1==3){//还有一组 
			ANS++;
		}
		else if((a1+n)-a2+1>=4){
			if(((a1+n)-a2+1)%2==0){
				q2.push((a1+n)-a2+1);
			}
			else q1.push((a1+n)-a2+1);
		}
		while((q1.size()>0||q2.size()>0)&&y>0){
			int t;
			if(q1.size()>0){
				t=q1.top();
				q1.pop();
			}
			else{
				t=q2.top();
				q2.pop();
			}
			if(y>=(t-2)/2){
				y-=(t-2)/2;
				ANS+=(t-2);
			}
			else{
				ANS+=y*2;
				y=0;
			}
		}
		if(f==0){
			y=yy;
			if(y==0){
				if(x==n-1){
					printf("%d\n",n-2);
				}
				else{
					printf("%d\n",max((x-2),0));
				}
			}
			else{
				int bian=n-x+2;//剩余bian边形 
				int xiaohao=(bian-2)/2;
				if(xiaohao<=y){
					printf("%d\n",n-2);
				}
				else{
					printf("%d\n",(x-2)+2*y);
				}
			}
		}
		else printf("%d\n",ANS);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
