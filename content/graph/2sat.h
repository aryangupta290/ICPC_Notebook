/**
 * Author: Emil Lenngren, Simon Lindholm
 * Date: 2011-11-29
 * License: CC0
 * Source: folklore
 * Description: Valid Assignemnt
 * Usage:
 *  TwoSat ts(number of boolean variables);
 *  ts.either(0, \tilde3); // Var 0 is true or var 3 is false
 *  ts.setValue(2); // Var 2 is true
 *  ts.atMostOne({0,\tilde1,2}); // <= 1 of vars 0, \tilde1 and 2 are true
 *  ts.solve(); // Returns true iff it is solvable
 *  ts.values[0..N-1] holds the assigned values to the vars
 * Time: O(N+E), where N is the number of boolean variables, and E is the number of clauses.
 * Status: stress-tested
 */
#pragma once
struct two_sat {
int n; VVI g, gr; // gr is the reversed graph
VI comp,topo,ans,vis; // comp[v] ID of the SCC containing node v
two_sat() {}
two_sat(int _n) { init(_n); }
void init(int _n) {
n = _n;g.assign(2*n,VI());
gr.assign(2*n,VI());comp.resize(2*n);
vis.resize(2*n);ans.resize(2*n);}
void add(int u, int v) {
g[u].PB(v);gr[v].PB(u);}
// For the following three functions
// int x, bool val: if 'val' is true, we take the variable to be x. Otherwise we take it to be x's complement.
// At least one of them is true
void add_or(int i,bool f,int j,bool g){
add(i+(f?n:0),j+(g?0:n));add(j+(g?n:0),i+(f?0:n));}
// Only one of them is true
void add_xor(int i,bool f,int j,bool g){
add_or(i,f,j,g);add_or(i,!f,j,!g);}
// Both of them have the same value
void add_and(int i,bool f,int j,bool g){
add_xor(i,!f,j,g);}
// Topological sort
void dfs(int u) {vis[u]=1;
for(auto &v:g[u])if(!vis[v])dfs(v);topo.PB(u);}
// Extracting strongly connected components
void scc(int u, int id) {
vis[u]=1;comp[u]=id;
for (auto &v:gr[u])if(!vis[v])scc(v, id);}
// Returns true if the given proposition is satisfiable and constructs a valid assignment
bool satisfiable() {
fill(ALL(vis),0);
FOR(i,0,2*n)if(!vis[i])dfs(i);
fill(ALL(vis),0);reverse(ALL(topo));
int id = 0;for(auto &v:topo)
if(!vis[v])scc(v, id++);
// Constructing the answer
FOR(i,0,n){
if(comp[i]==comp[i + n]) return false;
ans[i] = (comp[i] > comp[i + n] ? 1 : 0);}
return true;}};