// CSES 1635 - Coin Combinations I
// https://cses.fi/problemset/task/1635
//
// Count the number of ORDERED sequences of coins (with repetition) summing
// to x, modulo 1e9+7. Ordered means [1,3] and [3,1] are counted separately.
//
// State:  dp[s] = number of ordered ways to reach sum s.
// Base:   dp[0] = 1 (one empty sequence).
// Trans:  for each s, dp[s] = sum over coins c (c <= s) of dp[s - c].
//
// Iterating sums in the OUTER loop preserves order: every position in the
// sequence independently picks any coin, so each coin is reconsidered for
// every prefix sum.

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

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int& c : coins) cin >> c;

    vector<ll> dp(x + 1, 0);
    dp[0] = 1;

    for (int s = 1; s <= x; ++s) {
        for (int c : coins) {
            if (c <= s) dp[s] = (dp[s] + dp[s - c]) % MOD;
        }
    }

    cout << dp[x] << '\n';
    return 0;
}
