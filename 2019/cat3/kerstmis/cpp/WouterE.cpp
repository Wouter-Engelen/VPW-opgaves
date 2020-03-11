#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> power10(11, 1);
set<int> quad;
vector<vector<int>> result_v;
vector<string> words;

void solve(vector<int> current, int char_index, int index, const set<int>& free, const map<char, int>& mapping) {
    if(index == words.size()){
        result_v.push_back(vector<int>(current.begin(), current.end() - 1));
    } 
    else if(char_index == words[index].size()){
        if(quad.find(current.back()) != quad.end()){
            current.push_back(0);
            solve(current, 0, index + 1, free, mapping);
        }
    } 
    else if(mapping.find(words[index][char_index]) != mapping.end()) {
        current.back() += power10[char_index] * mapping.at(words[index][char_index]);
        solve(current, char_index + 1, index, free, mapping);
    } 
    else {
        for(int i : free){
            set<int> next_free = free;
            next_free.erase(i);

            map<char, int> next_mapping = mapping;
            next_mapping[words[index][char_index]] = i;
            
            solve(current, char_index, index, next_free, next_mapping);
        }
    }
}

signed main() {
    for(int i = 1; i < 11; i++) power10[i] = power10[i - 1] * 10;
    for(int i = 0; i * i < power10[10]; i++) quad.insert(i * i);

    int cases;
    cin >> cases;
    
    string line;
    getline(cin, line);

    for(int nr = 1; nr <= cases; nr++){
        result_v.clear();
        words.clear();

        getline(cin, line);

        stringstream in(line);

        set<char> char_set;
        while(!in.eof()){
            string word;
            in >> word;
            words.push_back(string(word.rbegin(), word.rend()));
            for(char c : word) char_set.insert(c);
        }

        if(char_set.size() != 10){
            cout << nr << " ONMOGELIJK" << endl;
            continue;
        }

        set<int> free;
        for(int i = 0; i < 10; i++) free.insert(i);

        solve({0}, 0, 0, free, map<char, int>());

        if(result_v.empty()){
            cout << nr << " ONMOGELIJK" << endl;
        } else {
            sort(result_v.begin(), result_v.end());

            for(auto v : result_v){
                cout << nr;
                for(int x : v) cout << " " << x;
                cout << endl;
            }
        }
    }
}
