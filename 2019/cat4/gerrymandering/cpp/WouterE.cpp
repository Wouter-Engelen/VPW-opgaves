#include <bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 1LL << 60;

int b, h;
vector<vector<int>> grid;
map<tuple<int, int, int, int>, tuple<int, int, int>> cache;

tuple<int, int, int> update(tuple<int, int, int> result, int parity){
    if(parity > 0) get<0>(result)++;
    if(parity == 0) get<1>(result)++;
    if(parity < 0) get<2>(result)--;
    return result;
}

int sumX(int x, int y0, int y1){
    int parity = 0;
    for(int i = y0; i < y1; i++) parity += grid[x][i];
    return parity;
}

int sumY(int y, int x0, int x1){
    int parity = 0;
    for(int i = x0; i < x1; i++) parity += grid[i][y];
    return parity;
}

tuple<int, int, int> solve(int x0, int y0, int x1, int y1){
    if(x0 == x1 || y0 == y1) return {0, 0, 0};
    if(cache.find({x0, y0, x1, y1}) != cache.end()) return cache[{x0, y0, x1, y1}];
    
    return cache[{x0, y0, x1, y1}] = max(
        max(
            update(solve(x0 + 1, y0, x1, y1), sumX(x0, y0, y1)), 
            update(solve(x0, y0, x1 - 1, y1), sumX(x1 - 1, y0, y1))),
        max(
            update(solve(x0, y0 + 1, x1, y1), sumY(y0, x0, x1)),
            update(solve(x0, y0, x1, y1 - 1), sumY(y1 - 1, x0, x1))
        )
    );
}

signed main() {
    int cases;
    cin >> cases;

    for(int nr = 1; nr <= cases; nr++){
        cin >> b >> h;

        grid = vector<vector<int>>(b, vector<int>(h, 0));
        for(int i = 0; i < h; i++){
            string line;
            cin >> line;
            for(int j = 0; j < b; j++){
                grid[j][i] = line[j] == 'A' ? 1 : -1;
            }
        }

        cache.clear();
        auto result = solve(0, 0, b, h);
        cout << nr << " " << get<0>(result) << " " << get<1>(result) << " " << -get<2>(result) << endl;
    }
}
