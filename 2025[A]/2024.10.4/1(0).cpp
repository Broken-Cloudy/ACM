#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
struct Tree//�ֵ��� 
{
     int fail;//ʧ��ָ��
     int vis[26];//�ӽڵ��λ��
     int end;//����м�������������ڵ��β 
}AC[1000000];//Trie��
int cnt=0;//Trie��ָ�� 
inline void Build(string s)
{
        int l=s.length();
        int now=0;//�ֵ����ĵ�ǰָ�� 
        for(int i=0;i<l;++i)//����Trie��
        {
                if(AC[now].vis[s[i]-'a']==0)//Trie��û������ӽڵ�
                   AC[now].vis[s[i]-'a']=++cnt;//�������
                now=AC[now].vis[s[i]-'a'];//���¹��� 
        }
        AC[now].end+=1;//��ǵ��ʽ�β 
}
void Get_fail()//����failָ��
{
        queue<int> Q;//���� 
        for(int i=0;i<26;++i)//�ڶ����failָ����ǰ����һ��
        {
               if(AC[0].vis[i]!=0)
               {
                   AC[AC[0].vis[i]].fail=0;//ָ����ڵ�
                   Q.push(AC[0].vis[i]);//ѹ����� 
               }
        }
        while(!Q.empty())//BFS��failָ�� 
        {
              int u=Q.front();
              Q.pop();
              for(int i=0;i<26;++i)//ö�������ӽڵ�
              {
              	int v=AC[u].vis[i];
                        if(v)//��������ӽڵ�
                      {
                                AC[AC[u].vis[i]].fail=AC[AC[u].fail].vis[i];
                                    //�ӽڵ��failָ��ָ��ǰ�ڵ��
                                  //failָ����ָ��Ľڵ����ͬ�ӽڵ� 
                                Q.push(AC[u].vis[i]);//ѹ����� 
                      }
                      else//����������ӽڵ� 
                      AC[u].vis[i]=AC[AC[u].fail].vis[i];
                      //��ǰ�ڵ������ӽڵ�ָ��
                      //ǰ�ڵ�failָ�������ӽڵ� 
              }
        }
}
int AC_Query(string s)//AC�Զ���ƥ��
{
        int l=s.length();
        int now=0,ans=0;
        for(int i=0;i<l;++i)
        {
                now=AC[now].vis[s[i]-'a'];//����һ��
                for(int t=now;t;t=AC[t].fail)//ѭ�����
                {	
                	if(AC[t].end>=0){
                		ans+=AC[t].end;
                         AC[t].end=-1;
					}
                        else break;
                } 
        }
        return ans;
}
int main()
{
	freopen("1(0).in","r",stdin);freopen("1(0).out","w",stdout);
     int n;
     string s;
     cin>>n;
     for(int i=1;i<=n;++i)
     {
             cin>>s;
             Build(s);
     }
     AC[0].fail=0;//������־ 
     Get_fail();//���ʧ��ָ��
     cin>>s;//�ı��� 
     cout<<AC_Query(s)<<endl;
	 fclose(stdin);fclose(stdout);
     return 0;
}
