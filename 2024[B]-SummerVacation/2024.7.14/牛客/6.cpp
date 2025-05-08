#include<bits/stdc++.h>
#define int long long
using namespace std;
struct SegmentTree {
    int size;
    vector<int> values;
    SegmentTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        values.assign(2 * size, 0);
    }

    void build(const vector<int>& arr, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < arr.size()) {
                values[x] = arr[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, m);
        build(arr, 2 * x + 2, m, rx);
        values[x] = values[2 * x + 1] + values[2 * x + 2];
    }

    void build(const vector<int>& arr) {
        build(arr, 0, 0, size);
    }

    int maxSubarraySum(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return 0;
        if (lx >= l && rx <= r) return values[x];

        int m = (lx + rx) / 2;
        int leftSum = maxSubarraySum(l, r, 2 * x + 1, lx, m);
        int rightSum = maxSubarraySum(l, r, 2 * x + 2, m, rx);
        return max(leftSum, rightSum);
    }

    int maxSubarraySum(int l, int r) {
        return maxSubarraySum(l, r, 0, 0, size);
    }
};
signed main() {
    int n, q;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld",arr[i]);
    }
    SegmentTree st(n);
    st.build(arr);
    cin>>q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l; --r; 
        printf("%lld\n",st.maxSubarraySum(l, r + 1));
    }

    return 0;
}

