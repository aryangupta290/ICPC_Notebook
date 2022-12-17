/**
 * Author: Simon Lindholm
 * Date: 2016-10-08
 * License: CC0
 * Source: me
 * Description: Segment tree with ability to add or set values of large intervals, and compute max of intervals.
 * Can be changed to other things.
 * Use with a bump allocator for better performance, and SmallPtr or implicit indices to save memory.
 * Time: O(\log N).
 * Usage: Node* tr = new Node(v, 0, SZ(v));
 * Status: stress-tested a bit
 */
#pragma once
struct node {
    int sum, width; // width = # of leaves for node
    node operator+(const node &n) {
        return {max(sum, n.sum), width + n.width};}};
struct update {
    int value; bool type;// 0 = add, 1 = reset
    node operator()(const node &n) {
        if (type) return {n.width * value, n.width};
        else return {n.sum + value, n.width};}
    update operator+(const update &u) {
        if (u.type) return u;
        return {type, value + u.value};}};
template <typename T, typename U>
struct seg_tree_lazy {
    int S, H; T zero;
    vector<T> value; U noop;
    vector<bool> dirty; vector<U> prop;
    seg_tree_lazy<T, U>(int _S, T _zero = T(), U _noop = U()) {
        zero = _zero, noop = _noop;
        for (S = 1, H = 1; S < _S;) S *= 2, H++;
        value.resize(2 * S, zero), dirty.resize(2 * S, false);
        prop.resize(2 * S, noop);}
    void set_leaves(vector<T> &leaves) {
        copy(leaves.begin(), leaves.end(), value.begin() + S);
        for (int i = S - 1; i > 0; i--)
            value[i] = value[2 * i] + value[2 * i + 1];}
    void apply(int i, U &update) {
        value[i] = update(value[i]);
        if (i < S) {
            prop[i] = prop[i] + update;
            dirty[i] = true;}}
    void rebuild(int i) {
        for (int l = i / 2; l; l /= 2) {
            T combined = value[2 * l] + value[2 * l + 1];
            value[l] = prop[l](combined);}}
    void propagate(int i) {
        for (int h = H; h > 0; h--) {
            int l = i >> h;
            if (dirty[l]) {
                apply(2 * l, prop[l]);
                apply(2 * l + 1, prop[l]);
                prop[l] = noop;
                dirty[l] = false;}}}
    void upd(int i, int j, U update) {
        i += S, j += S;
        propagate(i), propagate(j);
        for (int l = i, r = j; l <= r; l /= 2, r /= 2) {
            if ((l & 1) == 1) apply(l++, update);
            if ((r & 1) == 0) apply(r--, update);}
        rebuild(i), rebuild(j);}
    T query(int i, int j) {
        i += S, j += S;
        propagate(i), propagate(j);
        T res_left = zero, res_right = zero;
        for (; i <= j; i /= 2, j /= 2) {
            if ((i & 1) == 1) res_left = res_left + value[i++];
            if ((j & 1) == 0) res_right = value[j--] + res_right;}
        return res_left + res_right;}};