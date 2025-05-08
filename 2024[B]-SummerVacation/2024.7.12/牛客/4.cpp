#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, l, r;
vector<int> a;
vector<vector<int> > dp;

signed main() {
    cin >> n >> l >> r;
    a.resize(n + 1);
    dp.resize(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        a[i] = (c == '1') ? 1 : 0;
    }

    // 计算前缀和
    vector<int> prefix0(n + 1, 0), prefix1(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix0[i] = prefix0[i - 1] + (a[i] == 0);
        prefix1[i] = prefix1[i - 1] + (a[i] == 1);
    }

    // 动态规划计算dp数组
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                int C0 = prefix0[k] - prefix0[i - 1];
                int C1 = prefix1[j] - prefix1[k];
                if (abs(C0 - C1) >= l && abs(C0 - C1) <= r) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + 1);
                }
            }
        }
    }

    cout << dp[1][n] << endl;
    return 0;
}

