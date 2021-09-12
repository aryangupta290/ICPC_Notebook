#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define ALL(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define SET(a,v) memset((a), (v), sizeof(a))
#define PB push_back
#define EB emplace_back
#define MP make_pair  
#define fst first
#define snd second
using ll = long long;
using dbl = double;
using PII = pair<int, int>;
using VI = vector<int>;

#define trace(...) { __f(#__VA_ARGS__, __VA_ARGS__); }
template<typename Arg> void __f(const char* name, Arg&& arg) {
  cerr << name << " = " << arg << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " = " << arg1<<" | ";
  __f(comma+1, args...);
}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; // OST: find_by_order, order_of_key
typedef tree<int, null_type, less<>, rb_tree_tag,
  tree_order_statistics_node_update> ordered_set;
// #pragma GCC optimize("Ofast")
// optimize("unroll-loops")
// target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
/*** RNGS ***/
SEED=chrono::steady_clock::now().time_since_epoch().count();
// or high_resolution_clock
mt19937 rng(SEED); /*or*/ random_device rd; mt19937 rng(rd());
uniform_int_distribution<> dis(MIN, MAX);// usage: dis(rng)
struct chash {int operator()(int x) const {return x^SEED;}};
gp_hash_table<int,int,chash>m;//use cc if very less updates
/*** FAST IO ***/
inline int scan(){bool y=0; int x=0; char c=getchar_unlocked();
while(c<'0'||c>'9'){ if(c=='-')y=1; c=getchar_unlocked();} 
while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';
c=getchar_unlocked();}
return y?-x:x; }

int main() {
#ifdef LOCAL_EXEC
  // freopen("sample.in", "r", stdin);
  // freopen("sample.out", "w", stdout);
#else
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
#endif
  return 0;
}
