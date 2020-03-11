#include <bits/stdc++.h>
using namespace std;
#define int long long

int w, d;

set<int> dwerg(int count, const vector<int>& source, int index = 0){
    if(count == 0) return {0};

    set<int> result;
    for(int i = index; i < source.size(); i++){
        for(int x : dwerg(count - 1, source, i + 1)){
            result.insert(source[i] + x);
        }
    }

    return result;
}

int solve(const vector<vector<int>>& data){
    int count = 0;
    while(true){
        count++;

        set<int> possible;
        possible.insert(0);

        for(auto v : data){
            set<int> next;

            for(int y : dwerg(count, v)){
                for(int x : possible) {
                    if(x + y <= w) next.insert(x + y);
                }
            }

            possible = next;
        }

        if(possible.empty()) return -1;
        if(possible.find(w) != possible.end()) return count;
    }
}

signed main() {
    int cases;
    cin >> cases;

    for(int nr = 1; nr <= cases; nr++){
        cin >> w >> d;

        vector<vector<int>> data(d);
        for(int i = 0; i < d; i++){
            int t;
            cin >> t;
            data[i] = vector<int>(t);
            for(int j = 0; j < t; j++) cin >> data[i][j];
        }

        int result = solve(data);

        cout << nr << " " << (result == -1 ? "ONMOGELIJK" : to_string(result)) << endl;
    }
}
