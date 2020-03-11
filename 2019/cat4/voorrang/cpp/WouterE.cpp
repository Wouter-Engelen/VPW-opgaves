#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int cases;
    cin >> cases;

    for(int nr = 1; nr <= cases; nr++){
        int t;
        cin >> t;

        map<pair<int, int>, set<pair<int, int>>> grid;
        for(int i = 0; i < t; i++){
            int x0, y0, x1, y1;
            cin >> x0 >> y0 >> x1 >> y1;
            grid[{x0, y0}].insert({x1, y1});
            grid[{x1, y1}].insert({x0, y0});
        }

        int ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by;

        int axd = grid[{ax, ay}].begin()->first - ax;               // Start direction
        int ayd = grid[{ax, ay}].begin()->second - ay;
        int bxd = grid[{bx, by}].begin()->first - bx;               // End direction
        int byd = grid[{bx, by}].begin()->second - by;

        map<tuple<int, int, int, int>, int> dist;
        dist[{ax, ay, axd, ayd}] = 0;

        using ii = tuple<int, int, int, int, int>;
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push({0, ax, ay, axd, ayd});

        while(!pq.empty()){
            int cost, x, y, dx, dy;                                 // Old position + current direction
            tie(cost, x, y, dx, dy) = pq.top();
            pq.pop();

            if(dist[{x, y, dx, dy}] < cost) continue;
            if(x + dx == bx && y + dy == by) break;

            for(auto next : grid[{x + dx, y + dy}]){
                if(x == next.first && y == next.second) continue;
                int dx1 = next.first - (x + dx);                    // New direction
                int dy1 = next.second - (y + dy);
                int new_cost = cost;

                int rdx = dy, rdy = -dx;                            // Right turn
                int ldx = -dy, ldy = dx;                            // Left turn

                if(grid[{x + dx, y + dy}].find({x + dx + rdx, y + dy + rdy}) != grid[{x + dx, y + dy}].end()){      // There is a street to the right
                    if(dx1 == dx && dy1 == dy) new_cost++;          // We go straight
                    if(dx1 == ldx && dy1 == ldy) new_cost++;        // We go Left
                }
                if(grid[{x + dx, y + dy}].find({x + dx + dx, y + dy + dy}) != grid[{x + dx, y + dy}].end()) {       // There is a opposite street
                    if(dx1 == ldx && dy1 == ldy) new_cost++;        // We go Left
                }

                if(dist.find({x + dx, y + dy, dx1, dy1}) == dist.end() || dist[{x + dx, y + dy, dx1, dy1}] > new_cost){
                    dist[{x + dx, y + dy, dx1, dy1}] = new_cost;
                    pq.push({new_cost, x + dx, y + dy, dx1, dy1});
                }
            }
        }

        if(dist.find({bx + bxd, by + byd, -bxd, -byd}) == dist.end()){
            cout << nr << " ONMOGELIJK" << endl;
        } else {
            cout << nr << " " << dist[{bx + bxd, by + byd, -bxd, -byd}] << endl;
        }
    }
}
