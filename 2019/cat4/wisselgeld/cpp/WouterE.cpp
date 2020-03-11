#include <bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 1LL << 60;

bool valid(vector<int> him, int sum, vector<int> target){
    sort(him.rbegin(), him.rend());
    sort(target.rbegin(), target.rend());

    int i = 0;
    vector<int> result;
    while(sum > 0){
        while(i < him.size() && him[i] > sum) i++;
        if(i == him.size()) return false;
        sum -= him[i];
        result.push_back(him[i]);
    }

    return target == result;
}

signed main(){
    int cases;
    cin >> cases;

    for(int nr = 1; nr <= cases; nr++){
        int c, t;
        cin >> c >> t;

        vector<int> me(t);
        for(int i = 0; i < t; i++) cin >> me[i];

        cin >> t;
        vector<int> him(t);
        for(int i = 0; i < t; i++) cin >> him[i];

        cin >> t;
        vector<int> target(t);
        for(int i = 0; i < t; i++) cin >> target[i];

        int sum = 0;
        for(int x : target) sum += x;

        if(!valid(him, sum, target)){
            cout << nr << " ONMOGELIJK" << endl;
        } else {
            vector<int> dp(sum + c + 1, inf);
            dp[0] = 0;

            sort(me.begin(), me.end());
            for(int x : me){
                for(int i = min(sum + c - x, c - 1); i >= 0; i--){
                    dp[i + x] = min(dp[i + x], dp[i] + 1);
                }
            }

            if(dp[sum + c] == inf){
                cout << nr << " ONMOGELIJK" << endl;
            } else {
                cout << nr << " " << dp[sum + c] << endl;
            }
        }
    }
}
