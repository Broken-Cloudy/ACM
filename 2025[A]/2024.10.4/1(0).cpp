#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
struct Tree//字典树 
{
     int fail;//失配指针
     int vis[26];//子节点的位置
     int end;//标记有几个单词以这个节点结尾 
}AC[1000000];//Trie树
int cnt=0;//Trie的指针 
inline void Build(string s)
{
        int l=s.length();
        int now=0;//字典树的当前指针 
        for(int i=0;i<l;++i)//构造Trie树
        {
                if(AC[now].vis[s[i]-'a']==0)//Trie树没有这个子节点
                   AC[now].vis[s[i]-'a']=++cnt;//构造出来
                now=AC[now].vis[s[i]-'a'];//向下构造 
        }
        AC[now].end+=1;//标记单词结尾 
}
void Get_fail()//构造fail指针
{
        queue<int> Q;//队列 
        for(int i=0;i<26;++i)//第二层的fail指针提前处理一下
        {
               if(AC[0].vis[i]!=0)
               {
                   AC[AC[0].vis[i]].fail=0;//指向根节点
                   Q.push(AC[0].vis[i]);//压入队列 
               }
        }
        while(!Q.empty())//BFS求fail指针 
        {
              int u=Q.front();
              Q.pop();
              for(int i=0;i<26;++i)//枚举所有子节点
              {
              	int v=AC[u].vis[i];
                        if(v)//存在这个子节点
                      {
                                AC[AC[u].vis[i]].fail=AC[AC[u].fail].vis[i];
                                    //子节点的fail指针指向当前节点的
                                  //fail指针所指向的节点的相同子节点 
                                Q.push(AC[u].vis[i]);//压入队列 
                      }
                      else//不存在这个子节点 
                      AC[u].vis[i]=AC[AC[u].fail].vis[i];
                      //当前节点的这个子节点指向当
                      //前节点fail指针的这个子节点 
              }
        }
}
int AC_Query(string s)//AC自动机匹配
{
        int l=s.length();
        int now=0,ans=0;
        for(int i=0;i<l;++i)
        {
                now=AC[now].vis[s[i]-'a'];//向下一层
                for(int t=now;t;t=AC[t].fail)//循环求解
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
     AC[0].fail=0;//结束标志 
     Get_fail();//求出失配指针
     cin>>s;//文本串 
     cout<<AC_Query(s)<<endl;
	 fclose(stdin);fclose(stdout);
     return 0;
}
