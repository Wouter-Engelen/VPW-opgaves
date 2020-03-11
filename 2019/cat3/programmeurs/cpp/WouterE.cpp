#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int cases;
    cin >> cases;

    for(int nr = 1; nr <= cases; nr++){
        int p, v;
        cin >> p >> v;

        vector<int> ps(p), vs(v);
        for(int i = 0; i < p; i++) cin >> ps[i];
        for(int i = 0; i < v; i++) cin >> vs[i];

        sort(ps.begin(), ps.end());
        sort(vs.begin(), vs.end());

        int mx = 0, i = 0, j = 0;
        while(i < ps.size() && j < vs.size()){
            while(i < ps.size() && ps[i] < vs[j] - 1) i++;
            while(j < vs.size() && vs[j] < ps[i] - 1) j++;
            if(abs(ps[i] - vs[j]) <= 1){
                mx++, i++, j++;
            }
        }

        cout << nr << " " << mx << endl;
    }
}
