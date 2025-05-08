#include<iostream>
#include<string>
using namespace std;
char c[129];
int n;
void permute(int l, int r) {
    if(l==r){
        for(int i=0;i<n;i++)putchar(c[i]);putchar('\n');
    } 
	else{
        for(int i = l; i <= r; i++) {
            swap(c[l], c[i]);      // 将第l个和第i个元素交换
            permute(l + 1, r);  // 递归排列剩下的部分
            swap(c[l], c[i]);      // 回溯时交换回来，恢复原状
        }
    }
}
int main() {
    cin>>n;
    for (int i = 0; i < n; i++) {
        c[i] += ('a' + i);// 生成前n个小写字母
    }
    permute(0,n - 1);
    return 0;
}

