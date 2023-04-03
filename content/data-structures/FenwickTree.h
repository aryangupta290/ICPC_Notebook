/**
 * Author: Lukas Polacek
 * Date: 2009-10-30
 * License: CC0
 * Source: folklore/TopCoder
 * Description: Computes partial sums a[0] + a[1] + ... + a[pos - 1], and updates single elements a[i],
 * taking the difference between the old and new value.
 * Time: Both operations are $O(\log N)$.
 * Status: Stress-tested
 */

#pragma once
struct FT{vector<ll>s;
FT()=default;FT(int n):s(n){}
void update(int pos,ll dif){//a[pos]+=dif
for(;pos<SZ(s);pos|=pos+1)s[pos]+=dif;}
ll query(int pos){//sum of values in[0,pos)
ll res=0;
for(;pos>0;pos&=pos-1)res+=s[pos-1];
return res;}};
