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
#define lc(x) (x << 1) + 1
#define rc(x) (x << 1) + 2
struct node {
	int val, l1 = 0, stat = 0;
};
node f(node a, node b) {}
struct lazySegTree {
	vector<node> t;
	node zer;
	int n;
	lazySegTree(int n_, node zer_) : n(n_), t(4 * n_, zer_), zer(zer_) {}
	node query_H(int ind, int lo, int hi, int L, int R) {
		push(ind, lo, hi);
		if (R < lo || hi < L) return zer;
		if (L <= lo && hi <= R) return t[ind];
		int mid = (lo + hi) / 2;
		return f(query_H(lc(ind), lo, mid, L, R), query_H(rc(ind), mid + 1, hi, L, R));
	}
	void update_H(int ind, int lo, int hi, int L, int R, int stat, int x) {
		push(ind, lo, hi);
		if (R < lo || hi < L) return;
		if (L <= lo && hi <= R) {
			t[ind].stat = stat;
			t[ind].l1 = x;
			push(ind, lo, hi);
			return;
		}
		int mid = (lo + hi) / 2;
		update_H(lc(ind), lo, mid, L, R, stat, x), update_H(rc(ind), mid + 1, hi, L, R, stat, x);
		t[ind] = f(t[lc(ind)], t[rc(ind)]);
	}
	void push(int ind, int lo, int hi) {
		if (t[ind].stat == 0) return;
		t[ind].val += (hi - lo + 1) * t[ind].l1;
		int mid = (lo + hi) / 2;
		if (lo != hi) {
			t[lc(ind)].stat = t[ind].stat, t[lc(ind)].l1 += t[ind].l1;
			t[rc(ind)].stat = t[ind].stat, t[rc(ind)].l1 += t[ind].l1;
		}
		t[ind].stat = t[ind].l1 = 0;
	}
	void update(int L, int R, int s, int x) { update_H(0, 0, n - 1, L, R, s, x); }
	node query(int L, int R) { return query_H(0, 0, n - 1, L, R); }
};