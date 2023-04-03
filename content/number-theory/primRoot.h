/**
 * Author: Simon Lindholm
 * Date: 2015-06-23
 * License: CC0
 * Source: own work
 * Description: Calculates ncr for large N and prime Mod
 * Status: Tested for all |k|,|c|,to,m <= 50, and on kattis:aladin
 */

#pragma once
int PrimRoot(int p,int x){
//finds primitive root of prime p greater than x(If it doesnt exist,returns 0)
vector<int>v;int t=p-1;REP(i,2,t+1){
if(i*i>t)break;if(t%i==0){v.PB((p-1)/i);
while(t%i==0){t/=i;}}}
if(t>1)v.PB((p-1)/t);REP(i,x+1,p){
ll flag=0;REP(j,0,((ll)v.size())){
if(powM(i,v[j],p)==1){flag=1;break;}}
if(flag==0){return i;}}return 0;}
