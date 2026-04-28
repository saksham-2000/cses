// CSES 1634 - Minimizing Coins
// https://cses.fi/problemset/task/1634
//
// Given coin denominations c[0..n-1] (unlimited supply), find the minimum
// number of coins summing to x, or -1 if impossible.
//
// State:  dp[s] = fewest coins needed to make sum s.
// Base:   dp[0] = 0; every other entry starts at INF.
// Trans:  dp[s] = min over coins c (c <= s) of dp[s - c] + 1.

#include <bits/stdc++.h>
using namespace std;

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

    // INF / 2 keeps dp[s - c] + 1 from overflowing when s is unreachable.
    const int INF = INT_MAX / 2;
    vector<int> dp(x + 1, INF);
    dp[0] = 0;

    for (int s = 1; s <= x; ++s) {
        for (int c : coins) {
            if (c <= s && dp[s - c] + 1 < dp[s]) {
                dp[s] = dp[s - c] + 1;
            }
        }
    }

    cout << (dp[x] == INF ? -1 : dp[x]) << '\n';
    return 0;
}
