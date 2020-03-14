#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> cache;

int find_maximum(const vector<int>& pizza, int left, int right, int leftover) {
	left = (left + pizza.size()) % pizza.size(); 
	right = (right + pizza.size()) % pizza.size();

	if (left == right) return pizza[left];
	if (cache.find({ left, right }) != cache.end()) return cache.at({ left, right });
	
	return cache[{left, right}] = max(
		leftover - find_maximum(pizza, left - 1, right, leftover - pizza[left]),
		leftover - find_maximum(pizza, left, right + 1, leftover - pizza[right])
	);
}

int solve(const vector<int>& pizza) {
	int total = 0;
	for (int a : pizza) total += a;

	int best = 0;
	for (int i = 0; i < pizza.size(); i++) {
		best = max(best, find_maximum(pizza, i, i + 1, total));
	}

	return best;
}

int main() {
	int cases;
	cin >> cases;

	for (int nr = 1; nr <= cases; nr++) {
		int c;
		cin >> c;

		vector<int> pizza(c);
		for (int k = 0; k < c; k++) cin >> pizza[k];

		cache.clear();
		cout << solve(pizza) << endl;
	}
}
