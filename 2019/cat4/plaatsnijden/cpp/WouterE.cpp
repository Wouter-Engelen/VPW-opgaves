#include <bits/stdc++.h>
using namespace std;
#define int long long

map<pair<int, int>, set<set<pair<int, int>>>> cache;

void solve(int b, int h){
    if(cache.find({b, h}) != cache.end()) return;

    set<set<pair<int, int>>> result = {{{min(b, h), max(b, h)}}};

    for(int q = 0; q < 2; q++){
        swap(b, h);

        for(int i = 1; i < b; i++){
            solve(i, h);
            solve(b - i, h);

            for(auto l : cache[{i, h}]){
                for(auto r : cache[{b - i, h}]){
                    r.insert(l.begin(), l.end());
                    result.insert(r);
                }
            }
        }
    }

    cache[{b, h}] = cache[{h, b}] = result;
}

signed main(){
    int cases;
    cin >> cases;

    for(int nr = 1; nr <= cases; nr++){
        int b, h;
        cin >> b >> h;

        solve(min(b, h), max(b, h));

        int best = 0;
        for(auto s : cache[{b, h}]) best = max(best, (int)s.size());

        cout << nr << " " << best << endl;
    }
}
