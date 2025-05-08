#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1e9 + 7;
int n, k, i, w, d, a[1000009], p[1000009], ANS = 1;

// �������㷨������ x^y % inf
int fast(int x, int y) {
    int ans = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            ans = (ans * x) % inf;  // ֻ������Ҫʱ��ȡģ
        }
        x = (x * x) % inf;  // ֻ������Ҫʱ��ȡģ
        y /= 2;
    }
    return ans;
}

int x, y;

// ��չŷ������㷨�����ģ��Ԫ
void exgcd(long long a, long long b) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b);
    int t = x;
    x = y;
    y = t - (a / b) * y;
}

signed main() {
	freopen("20.in","r",stdin);freopen("20.out","w",stdout);
    ios::sync_with_stdio(false); // �Ż��������
    cin.tie(0);

    cin >> w >> d;

    if (d == 0) {
        for (i = 1; i <= w; i++) {
            cin >> p[i] >> a[i];
            ANS = (ANS * (a[i] + 1)) % inf;  // ֱ�Ӽ���Լ������
        }
    } else {
        for (i = 1; i <= w; i++) {
            cin >> p[i] >> a[i];
            int term1 = fast(p[i], d * (a[i] + 1)) - 1;
            if (term1 < 0) term1 += inf;  // ��֤ term1 �Ǹ�
            ANS = (ANS * term1) % inf;

            int term2 = fast(p[i], d) - 1;
            if (term2 < 0) term2 += inf;  // ��֤ term2 �Ǹ�
            exgcd(term2, inf);
            x = (x % inf + inf) % inf;  // ��֤ x �Ǹ�

            ANS = (ANS * x) % inf;
        }
    }

    cout << ANS << endl;

    return 0;
}

