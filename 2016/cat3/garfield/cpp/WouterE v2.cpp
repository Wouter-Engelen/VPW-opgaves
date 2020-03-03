#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> nodes;
int t;

int dist(int i, int j){
    return abs(nodes[i].first - nodes[j].first) + abs(nodes[i].second - nodes[j].second);
}

int solve() {
    map<pair<int, vector<bool>>, int> dp;

    vector<bool> mask(nodes.size(), true);
    mask[0] = false;
    dp[{0, mask}] = t;

    int count = -1;
    while(!dp.empty()) {
        map<pair<int, vector<bool>>, int> next;

        for(auto& p : dp){
            for(int i = 1; i < nodes.size(); i++){
                int time_left = p.second - (dist(p.first.first, i) + 1);
                if(p.first.second[i] && dist(i, 0) <= time_left) {
                    vector<bool> mask = p.first.second;
                    mask[i] = false;

                    if(next.find({i, mask}) == next.end() || next[{i, mask}] < time_left) {
                        next[{i, mask}] = time_left;
                    }
                }
            }
        }

        dp = next;
        count++;
    }

    return count;
}

int main(){
    int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int b, h;
		cin >> b >> h >> t;

		nodes.clear();
		for (int j = 0; j < h; j++) {
			for (int k = 0; k < b; k++) {
				char c;
				cin >> c;
				if (c == 'G') {
					nodes.insert(nodes.begin(), { k, j });
				}
				else if(c == 'E') {
					nodes.push_back({ k, j });
				}
			}
		}

		cout << i << " " << solve() << endl;
	}
}
