// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (val): no. of values less than val
// find_by_order (k): kth largest element.(0-based)
#define int long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define SET(a, v) memset((a), (v), sizeof(a))
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define F first
#define S second
using LL = long long;
using dbl = double;
using II = pair<int, int>;
using VI = vector<int>;
using VII = vector<II>;
using VVI = vector<VI>;
#define endl "\n"
const long long mod = 1e9 + 7;
signed main() {
  // freopen("sample.in", "r", stdin);
  // freopen("sample.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit); // RTE if out of bound
  return 0;
}