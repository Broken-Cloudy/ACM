#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cnt,i,j,tow,ans,a[5000009],Map[5000009],in[5000009];
char T[5000009];
string S[5000009];
struct Trie{
	int fail;//ʧ��ָ�� 
	int son[26];
	//Map[i]��ʾiָ���һ����s[i]��ͬ��ģʽ��s[x],Map[i]=x,����AC[tow].endָ��x; 
	int end;//�Դ˽���β�ĵ�x��ģʽ��,����������ж��Ƿ��ظ� 
	int ans;
}AC[5000009];
int num(char c){return (c-'a');}
void build(int x){//��Trie�� 
	int i,tow=0;
	int len=S[x].length();
	for(i=0;i<len;i++){
		if(!AC[tow].son[num(S[x][i])])AC[tow].son[num(S[x][i])]=++cnt;
		tow=AC[tow].son[num(S[x][i])];
	}
	if(!AC[tow].end)AC[tow].end=x,Map[x]=x;
	else Map[x]=AC[tow].end;
}
void build_fail(){
	int i;
	queue<int>Q;
	AC[0].fail=0;//������־ 
	for(i=0;i<26;i++){//����Ԥ�����ڶ���ָ����ڵ� 
		if(AC[0].son[i]){
			AC[AC[0].son[i]].fail=0;//ָ����ڵ�
			in[AC[AC[0].son[i]].fail]++;
			Q.push(AC[0].son[i]);//ѹ����� 
		}
	}
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(i=0;i<26;i++){
			//�½���ʶv��ֻ�������ж���������������ֵ���������� 
			if(AC[u].son[i]){//�ı��η��� 
				AC[AC[u].son[i]].fail=AC[AC[u].fail].son[i];//����ʧ��ָ��Ķ��� 
				in[AC[AC[u].son[i]].fail]++;//��� ֻ������� 
				Q.push(AC[u].son[i]);
			}
			else AC[u].son[i]=AC[AC[u].fail].son[i];//�����η��� 
		}
	}
}
void topu(){
	int i;
	queue<int>Q;
	for(i=1;i<=cnt;i++)if(!in[i])Q.push(i);
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		a[AC[u].end]=AC[u].ans;
		int v=AC[u].fail;in[v]--;
		AC[v].ans+=AC[u].ans;
		if(!in[v])Q.push(v);
	}
}
signed main(){
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>S[i];
		build(i);
	}
	build_fail();tow=0;
	scanf("%s",T+1);
	int len=strlen(T+1);
	for(i=1;i<=len;i++){
		tow=AC[tow].son[num(T[i])];
		AC[tow].ans++;
	}
	topu();
	for(i=1;i<=n;i++){
		printf("%lld\n",a[Map[i]]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
