/**
 * Author: Anurudh Peduri
 * Date: 2020-01-13
 * License: CC0
 * Description: Add lines $y = ax + b$ and
 * query for min at given $x$ Time: $O(log
 * n)$ per update/query.
 */

#pragma once
struct Line{//gives minimum
mutable int k,m,p;//line kx+m
bool operator<(const Line&o)const
{return k<o.k;}bool operator<(int x)const
{return p<x;}};
struct LineContainer:multiset<Line,less<>>
{//(for doubles,use inf=1/.0,div(a,b)
//=a/b)static const int inf=LLONG_MAX;
int div(int a,int b){//floored division
return a/b-((a^b)<0&&a%b);}
bool isect(iterator x,iterator y){
if(y==end())return x->p=inf,0;
if(x->k==y->k)x->p=x->m>y->m?inf:-inf;else
x->p=div(y->m-x->m,x->k-y->k);
return x->p>=y->p;}void add(int k,int m){
auto z=insert({k,m,0}),y=z++,x=y;
while(isect(y,z))z=erase(z);
if(x!=begin()&&isect(--x,y))
isect(x,y=erase(y));while((y=x)!=begin()&&
(--x)->p>=y->p)isect(x,erase(y));}
int query(int x){assert(!empty());
auto l=*lower_bound(x);return l.k*x+l.m;}
};
