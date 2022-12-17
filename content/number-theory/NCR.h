/**
 * Author: Simon Lindholm
 * Date: 2015-06-23
 * License: CC0
 * Source: own work
 * Description: Calculates ncr for large N and prime Mod
 * Status: Tested for all |k|,|c|,to,m <= 50, and on kattis:aladin
 */
#pragma once
// 3456789012345678901234567890123456789012345678901234
#define MAX_N_FACT (int)3e5 + 5
vector<long long> factorial(MAX_N_FACT, 1), inverse_factorial(MAX_N_FACT, 1), inv(MAX_N_FACT, 1);
void prec_factorials() {
    for (int i = 2; i < MAX_N_FACT; i++) {
        factorial[i] = factorial[i - 1] * i % mod;
        inv[i] = (mod - (mod / i) * inv[mod % i] % mod);
        inverse_factorial[i] = (inv[i] * inverse_factorial[i - 1]) % mod;
    }
}
long long ncr(int n, int k) {
    return factorial[n] * inverse_factorial[k] % mod * inverse_factorial[n - k] % mod;
}