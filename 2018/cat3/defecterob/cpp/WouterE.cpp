#include <bits/stdc++.h>
using namespace std;
#define int long long

int minimal_length(string a, string b){
    int error_count = 0;
    for(int i = 0; i < a.size(); i++) error_count += a[i] != b[i];
    return error_count + error_count % 2;
}

string solve(string start, string target){      // Brute force with priority queue and heuristic (A*)
    using ii = tuple<int, string, string>;
    auto comp = [](ii l, ii r) {
        if(get<0>(l) != get<0>(r)) return get<0>(l) > get<0>(r);
        return get<1>(l) > get<1>(r);
    };
    priority_queue<ii, vector<ii>, decltype(comp)> pq(comp);
    pq.push({minimal_length(start, target), "", start});

    unordered_set<string> seen;

    while(true){
        int len; string ops, current;
        tie(len, ops, current) = pq.top();
        pq.pop();

        if(current == target) return ops;
        if(!seen.insert(current).second) continue;

        for(int i = 0; i < current.size(); i++){
            for(int j = i + 1; j < current.size(); j++){
                string next = current;
                swap(next[i], next[j]);

                string next_ops = ops;
                next_ops += 'A' + i;
                next_ops += 'A' + j;
                
                pq.push({next_ops.size() + minimal_length(next, target), next_ops, next});
            }
        }
    }
}

signed main() {
    int cases;
    cin >> cases;

    for(int nr = 1; nr <= cases; nr++){
        string fout, correct;
        cin >> fout >> correct;

        if(fout == correct){
            cout << nr << " correct" << endl;
        } 
        else if(multiset<char>(fout.begin(), fout.end()) != multiset<char>(correct.begin(), correct.end())) {
            cout << nr << " onmogelijk" << endl;
        }
        else {
            cout << nr << " " << solve(fout, correct) << endl;
        }
    }
}
