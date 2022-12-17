/**
 * Author: Benjamin Qi, Oleksandr Kulkov, chilli
 * Date: 2020-01-12
 * License: CC0
 * Source: https://codeforces.com/blog/entry/53170, https://github.com/bqi343/USACO/blob/master/Implementations/content/graphs%20(12)/Trees%20(10)/HLD%20(10.3).h
 * Description: Decomposes a tree into vertex disjoint heavy paths and light
 * edges such that the path from any leaf to the root contains at most log(n)
 * light edges. Code does additive modifications and max queries, but can
 * support commutative segtree modifications/queries on paths and subtrees.
 * Takes as input the full adjacency list. VALS\_EDGES being true means that
 * values are stored in the edges, as opposed to the nodes. All values
 * initialized to the segtree default. Root must be 0.
 * Time: O((\log N)^2)
 * Status: stress-tested against old HLD
 */
#pragma once
// 3456789012345678901234567890123456789012345678901234
VI sz, sc, hd, en, ex, par, dep;
seg_tree_lazy<node, update> st(1, {0, 0}, {0, 0}); // for alter accordingly
int timer = -1;
void hld(int u, int p, int ch, int d) {
    hd[u] = ch; en[u] = ++timer; par[u] = p; dep[u] = d;
    if (sc[u] != -1) hld(sc[u], u, ch, d + 1);
    for (auto e : g[u]) {
        int v = U[e] ^ V[e] ^ u;
        if (v == p || v == sc[u]) continue;
        hld(v, u, v, d + 1);}
    ex[u] = timer;}
int path(int x, int y) {
    int ma = (int)-1e9;
    while (hd[x] != hd[y]) {
        if (dep[hd[x]] < dep[hd[y]]) swap(x, y);
        ma = max(st.query(en[hd[x]], en[x]).sum, ma); // for hd[x] -> x
        x = par[hd[x]];
    }
    if (dep[x] < dep[y]) swap(x, y);
    ma = max(ma, st.query(en[y], en[x]).sum); // for y -> x
    return ma;}