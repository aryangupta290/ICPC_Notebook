/**
 * Author: Simon Lindholm
 * Date: 2020-10-12
 * License: CC0
 * Source: https://en.wikipedia.org/wiki/Misra_%26_Gries_edge_coloring_algorithm
 * https://codeforces.com/blog/entry/75431 for the note about bipartite graphs.
 * Description: color edges of a bipartite graph with minimum colors
 * Time: O(NM)
 * Status: stress-tested, tested on kattis:gamescheduling
 */

#pragma once

//change max-values of m and n according to problem
//v is vector of edges and cv is the color of corresponding edge
//solve returns the maximum number of colors used
//call the solve function to get the colors from 1 to d in O(n*m)
//Space occupied by deg is 2*(max nodes possible on 1 side)
//Space occupied by has is 2*2*(max nodes possible on 1 side)*(max colors possible)
//Space occupied by deg is(max edges possible)
struct edge_color{
int deg[2][MAXN];II has[2][MAXN][MAXN];
int color[MAXM];int c[2];
void clear(int n){for(int t=0;t<2;t++){
for(int i=0;i<=n;i++){deg[t][i]=0;
for(int j=0;j<=n;j++){
has[t][i][j]=II(0,0);}}}}
void dfs(int x,int p){
auto i=has[p][x][c[!p]];
if(has[!p][i.first][c[p]].second)
dfs(i.first,!p);else
has[!p][i.first][c[!p]]=II(0,0);
has[p][x][c[p]]=i;
has[!p][i.first][c[p]]=II(x,i.second);
color[i.second]=c[p];}
int solve(vector<II>v,vector<int>&cv){
int m=SZ(v);int ans=0;
for(int i=1;i<=m;i++){
int x[2];x[0]=v[i-1].first;
x[1]=v[i-1].second;for(int d=0;d<2;d++){
deg[d][x[d]]+=1;ans=max(ans,deg[d][x[d]]);
for(c[d]=1;has[d][x[d]][c[d]].second;c[d]++)
;}if(c[0]!=c[1])dfs(x[1],1);
for(int d=0;d<2;d++)has[d][x[d]][c[0]]=II(x[!d],i);
color[i]=c[0];}cv.resize(m);
for(int i=1;i<=m;i++){
cv[i-1]=color[i];color[i]=0;}
return ans;}};
