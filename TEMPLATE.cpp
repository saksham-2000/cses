#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define vl vector<ll>
#define vpll vector< pll >
#define vvl vector< vl >
#define pb push_back
#define PI acos(-1)
#define cld complex<ld>
#define fix(f, n) fixed << setprecision(n) << f
#define all(x) x.begin(), x.end()
#define popcount(x) __builtin_popcountll(x)
#define sz(x) ((ll)x.size())
#define mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifndef ONLINE_JUDGE
namespace _debug {
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
void __print(const complex<long double> &x) {
  cerr << '{';
  __print(x.real());
  cerr << ',';
  __print(x.imag());
  cerr << '}';
}
template <typename T, typename V> void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T> void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x)
    cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}

template <typename T> void debug1d(const char *name, T *a, int n) {
  cerr << "[" << name << "]: ";
  for (int i = 0; i < n; i++) {
    if (i)
      cerr << " ";
    __print(a[i]);
  }
  cerr << "\n";
}
template <typename T> void debug2d(const char *name, T &g, int n, int m) {
  cerr << "[" << name << "] " << n << "x" << m << ":\n";
  for (int i = 0; i < n; i++) {
    cerr << " " << i << "| ";
    for (int j = 0; j < m; j++) {
      if (j)
        cerr << " ";
      cerr << g[i][j];
    }
    cerr << "\n";
  }
}
template <typename T> void debug3d(const char *name, T &g, int n, int m, int k) {
  cerr << "[" << name << "] " << n << "x" << m << "x" << k << ":\n";
  for (int i = 0; i < n; i++) {
    cerr << " [" << i << "]:\n";
    for (int j = 0; j < m; j++) {
      cerr << "  " << j << "| ";
      for (int l = 0; l < k; l++) {
        if (l)
          cerr << " ";
        cerr << g[i][j][l];
      }
      cerr << "\n";
    }
  }
}

auto _start = chrono::high_resolution_clock::now();
void _timer() {
  auto _now = chrono::high_resolution_clock::now();
  cerr << "Time: " << chrono::duration<double, milli>(_now - _start).count()
       << " ms\n";
}
} // namespace _debug

using namespace _debug;

#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)                                              
#define debug_1d(a,n) debug1d(#a, a, n)
#define debug_2d(g, n, m) debug2d(#g, g, n, m)
#define debug_3d(g, n, m, k) debug3d(#g, g, n, m, k)
#define timer() _timer()
#else
#define debug(x...)
#define debug_arr(a, n)
#define debug_grid(g, n, m)
#define debug_3d(g, n, m, k)
#define timer()
#endif

void OJ() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

int main() {
  OJ();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vvl v(5, vl(3));

  v[2][2] = 10;
  v[1][2] = 5;

  debug_2d(v, 5, 3);

  // code goes here.

  return 0;
}
