/**
 * Author: Johan Sannemo
 * Date: 2015-02-06
 * License: CC0
 * Source: Folklore
 * Description: Assumes the root node points to itself.
 * Time: construction $O(N \log N)$, queries $O(\log N)$
 * Status: Tested at Petrozavodsk, also stress-tested via LCA.cpp
 */
#pragma once

VI U, V, W, isDel;
int dp[n][log2(n) + 1];
// (avoid deleted edges) in all 3 DFS
void decompose(int root, int p) {
    dfs_sz(root, -1); // calc sizes of subtrees
    int c = get_centroid(root, -1, sz[root]);  // if sz[v] * 2 > sz[root] return get_centroid(v) else return u
    if (p == -1) p = root;
    // Add edge btwn p and c here
    dfs(c);  // to compute functions
    for (auto e : g[root]) {
        if (isDel[e]) continue;
        isDel[e] = 1;
        int v = U[e] ^ V[e] ^ u;
        decompose(v, root);}}