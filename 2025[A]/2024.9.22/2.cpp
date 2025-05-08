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
            swap(c[l], c[i]);      // ����l���͵�i��Ԫ�ؽ���
            permute(l + 1, r);  // �ݹ�����ʣ�µĲ���
            swap(c[l], c[i]);      // ����ʱ�����������ָ�ԭ״
        }
    }
}
int main() {
    cin>>n;
    for (int i = 0; i < n; i++) {
        c[i] += ('a' + i);// ����ǰn��Сд��ĸ
    }
    permute(0,n - 1);
    return 0;
}

