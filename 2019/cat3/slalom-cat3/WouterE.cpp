#include <bits/stdc++.h>
using namespace std;
#define int long long

int next_power_of_two(const int x) {
	return x <= 1 ? 1 : 1 << (sizeof(int) * 8 - __builtin_clz(x - 1));
}

struct SegmentTree {
	int n, zero;
	vector<int> tree;

    function<int(int, int)> change = [](int a, int dx) { return a + dx; };
    function<int(int, int)> query = [](int a, int b) { return max(a, b); };
    
    SegmentTree(int N, int zero) : n(next_power_of_two(N)), zero(zero), tree(2 * n, zero) {}

	void update(int k, int dx) {
		k += n;
        tree[k] = change(tree[k], dx);
        for (k /= 2; k >= 1; k /= 2) {
            tree[k] = query(tree[2 * k], tree[2 * k + 1]);
        }
	}

	int range_query(int a, int b) {
        a += n; b += n;
        int s = zero;
        while (a <= b) {
            if (a % 2 == 1) s = query(s, tree[a++]);
            if (b % 2 == 0) s = query(s, tree[b--]);
            a /= 2; b /= 2;
        }
        return s;
    }
};

signed main() {
    int cases;
    cin >> cases;

    for(int nr = 1; nr <= cases; nr++){
        int b, l, n;
        cin >> b >> l >> n;

        vector<tuple<int, bool, int, int, int>> p;
        for(int i = 0; i < n; i++){
            int x, y, s;
            cin >> x >> y >> s;
            int dy = l - y - 1;
            p.push_back({x - dy, false, y, s, i});
            p.push_back({x + dy, true, -y, s, i});
        }
        sort(p.begin(), p.end());

        SegmentTree tree(p.size(), 0);
        vector<int> offset(n);
        int best = 0;
        
        for(int i = 0; i < p.size(); i++){
            int x, y, value, id; bool is_right;
            tie(x, is_right, y, value, id) = p[i];

            if(is_right){
                int result = value + tree.range_query(offset[id], i);
                tree.update(offset[id], result);
                best = max(best, result);
            } else {
                offset[id] = i;
            }
        }

        cout << nr << " " << best << endl;
    }
}
