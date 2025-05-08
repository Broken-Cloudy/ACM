#include<bits/stdc++.h>
#define int long long
using namespace std;
char s1[200009],s2[200009],c;
int len1,len2,T,i,j;
signed main(){
	freopen("4.in","r",stdin);freopen("4.out","w",stdout);
	cin>>T;getchar();
	while(T--){
		len1=len2=0;
		c=getchar();
		while(c!='\n'&&c!=-1&&c!=' '){
			s1[++len1]=c;
			c=getchar();
		}
		c=getchar();
		while(c!='\n'&&c!=-1&&c!=' '){
			s2[++len2]=c;
			c=getchar();
		}
		j=1;
		for(i=1;i<=len1;i++){
			if(j>len2)break;
			if(s1[i]==s2[j]){
				j++;
			}
			else if(s1[i]=='?'){
				s1[i]=s2[j];
				j++;
			}
		}
		if(j<=len2){
			printf("NO\n");
		}
		else{
			printf("YES\n");
			for(i=1;i<=len1;i++){
				if(s1[i]!='?'){
					putchar(s1[i]);
				}
				else putchar('a');
			}
			putchar('\n');
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
