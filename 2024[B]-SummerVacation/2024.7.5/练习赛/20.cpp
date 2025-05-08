#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1e9 + 7;
int n, k, i, w, d, a[1000009], p[1000009], ANS = 1;

// 快速幂算法，计算 x^y % inf
int fast(int x, int y) {
    int ans = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            ans = (ans * x) % inf;  // 只有在需要时才取模
        }
        x = (x * x) % inf;  // 只有在需要时才取模
        y /= 2;
    }
    return ans;
}

int x, y;

// 扩展欧几里得算法，求解模逆元
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
    ios::sync_with_stdio(false); // 优化输入输出
    cin.tie(0);

    cin >> w >> d;

    if (d == 0) {
        for (i = 1; i <= w; i++) {
            cin >> p[i] >> a[i];
            ANS = (ANS * (a[i] + 1)) % inf;  // 直接计算约数个数
        }
    } else {
        for (i = 1; i <= w; i++) {
            cin >> p[i] >> a[i];
            int term1 = fast(p[i], d * (a[i] + 1)) - 1;
            if (term1 < 0) term1 += inf;  // 保证 term1 非负
            ANS = (ANS * term1) % inf;

            int term2 = fast(p[i], d) - 1;
            if (term2 < 0) term2 += inf;  // 保证 term2 非负
            exgcd(term2, inf);
            x = (x % inf + inf) % inf;  // 保证 x 非负

            ANS = (ANS * x) % inf;
        }
    }

    cout << ANS << endl;

    return 0;
}

