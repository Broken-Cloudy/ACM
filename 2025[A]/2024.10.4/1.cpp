#include<bits/stdc++.h>
#define int long long
using namespace std;
int Case,n,m,cnt,i,j,tow,ans;
char S[1000009],T[1000009];
struct Trie{
	int fail;//ʧ��ָ�� 
	int son[26];
	int end;//�Դ˽���β���ַ��� 
}AC[1000009];
int num(char c){return (c-'a');}
void build(){//��Trie�� 
	int i,tow=0;
	int len=strlen(S+1);
	for(i=1;i<=len;i++){
		if(!AC[tow].son[num(S[i])])AC[tow].son[num(S[i])]=++cnt;
		tow=AC[tow].son[num(S[i])];
	}
	AC[tow].end++;
}
void build_fail(){
	int i;
	queue<int>Q;
	AC[0].fail=0;//������־ 
	for(i=0;i<26;i++){//����Ԥ�����ڶ���ָ����ڵ� 
		if(AC[0].son[i]){
			AC[AC[0].son[i]].fail=0;//ָ����ڵ�
			Q.push(AC[0].son[i]);//ѹ����� 
		}
	}
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(i=0;i<26;i++){
			//�½���ʶv��ֻ�������ж���������������ֵ���������� 
			if(AC[u].son[i]){//�ı��η��� 
				AC[AC[u].son[i]].fail=AC[AC[u].fail].son[i];//����ʧ��ָ��Ķ��� 
				Q.push(AC[u].son[i]);
			}
			else AC[u].son[i]=AC[AC[u].fail].son[i];//�����η��� 
		}
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>Case;
	while(Case--){
		scanf("%s",S+1);
		build();
	}
	build_fail();
	scanf("%s",T+1);
	int len=strlen(T+1);
	for(i=1;i<=len;i++){
		tow=AC[tow].son[num(T[i])];
		for(j=tow;j;j=AC[j].fail){
			if(AC[j].end>=0){
				ans+=AC[j].end;
				AC[j].end=-1;//�Ѿ�ͳ�Ƴ��ֹ��� 
			}
			else break;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
