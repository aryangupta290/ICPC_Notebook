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

// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")

/*** RNGS ***/
SEED = chrono::steady_clock::now().time_since_epoch().count();
// or `high_resolution_clock`
mt19937 rng(SEED); /* or */ random_device rd; mt19937 rng(rd());
uniform_int_distribution<> dis(MIN, MAX); // usage: dis(rng)

/*** FAST IO ***/
inline int scan() {
  bool y = 0; int x = 0;
  char c = getchar_unlocked();
  while (c < '0' || c > '9') {
    if (c == '-') y = 1;
    c = getchar_unlocked();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar_unlocked();
  }
  return y ? -x : x;
}
