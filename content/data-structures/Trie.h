/**
 * Author: someone on Codeforces
 * Date: 2017-03-14
 * Source: folklore
 * Description: krishna
 * Time: $O(\log N)$
 * Status: stress-tested
 */
#pragma once
// 3456789012345678901234567890123456789012345678901234
const int NX = int(1e6) + int(5e5);
int arr[NX][26];
int root;
int lastocc;
void Trie() {
    root = 0, lastocc = 0;
    memset(arr, 0, sizeof(int) * NX * 26);
}
void insert(const string &x) {
    int curptr = root;
    for (auto ch : x) {
        if (arr[curptr][ch - 'a'] == 0)
            arr[curptr][ch - 'a'] = ++lastocc;
        curptr = arr[curptr][ch - 'a'];
    }
}
int search(const string &x) {
    int curptr = root;
    for (auto ch : x) {
        if (arr[curptr][ch - 'a'] == 0)
            return 0;
        else
            curptr = arr[curptr][ch - 'a'];
    }
    return 1;
}