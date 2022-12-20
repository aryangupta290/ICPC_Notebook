/**
 * Author: Simon Lindholm
 * Date: 2018-07-06
 * License: CC0
 * Description:given a polygon A in order, returns count of points(integer) on boundary
 * Integer -> permutation can use a lookup table.
 * Time: O(n)
 */
#pragma once
int boundary(vector<pair<int, int>>& A) {
    int ats = A.size();
    for (int i = 0; i < A.size(); i++) {
        int dx = (A[i].first - A[(i + 1) % A.size()].first);
        int dy = (A[i].second - A[(i + 1) % A.size()].second);
        ats += abs(__gcd(dx, dy)) - 1;
    }
    return ats;
}