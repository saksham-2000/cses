// CSES 1746 - Array Description
// https://cses.fi/problemset/task/1746
//
// Given an array of length n in which each entry is either 0 (unknown) or a
// value in [1, m], count the ways to replace every 0 so that
// |a[i] - a[i+1]| <= 1 for all i. Answer modulo 1e9+7.
//
// State:  dp[i][v] = number of valid ways to fill a[0..i] with a[i] = v.
// Trans:  dp[i][v] = dp[i-1][v-1] + dp[i-1][v] + dp[i-1][v+1].
// If a[i] is fixed (non-zero), only column v == a[i] is reachable.
// Answer: sum over v of dp[n-1][v].

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1'000'000'007;

void redirectIO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main() {
    redirectIO();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    // Columns are indexed 1..m; index 0 and m+1 act as zero-padded sentinels
    // so the v-1 / v+1 transitions don't need bounds checks.
    vector<vector<ll>> dp(n, vector<ll>(m + 2, 0));

    auto allowed = [&](int i, int v) {
        return a[i] == 0 || a[i] == v;
    };

    for (int v = 1; v <= m; ++v) {
        if (allowed(0, v)) dp[0][v] = 1;
    }

    for (int i = 1; i < n; ++i) {
        for (int v = 1; v <= m; ++v) {
            if (!allowed(i, v)) continue;
            dp[i][v] = (dp[i - 1][v - 1] + dp[i - 1][v] + dp[i - 1][v + 1]) % MOD;
        }
    }

    ll ans = 0;
    for (int v = 1; v <= m; ++v) ans = (ans + dp[n - 1][v]) % MOD;
    cout << ans << '\n';
    return 0;
}
