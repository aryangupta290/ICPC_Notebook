/**
 * Author: Lucian Bicsi
 * Date: 2017-10-31
 * License: CC0
 * Source: folklore
 * Description: Zero-indexed max-tree. Bounds are inclusive to the left and exclusive to the right. Can be changed by modifying T, f and unit.
 * Time: O(\log N)
 * Status: stress-tested
 */

#pragma once
template<typename T>struct segTree{T unit;
T(*f)(T obj1,T obj2);vector<T>s;int n;
segTree(int n,T(*c)(T obj1,T obj2),T def):s(2*n,def),n(n),f(c),unit(def){}
void update(int pos,T val){
for(s[pos+=n]=val;pos/=2;)
s[pos]=f(s[pos*2],s[pos*2+1]);}
T query(int b,int e){//query[b,e]e++;
T ra=unit,rb=unit;
for(b+=n,e+=n;b<e;b/=2,e/=2){
if(b%2)ra=f(ra,s[b++]);
if(e%2)rb=f(s[--e],rb);}
return f(ra,rb);}};
