#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int cases;
    cin >> cases;
    
    string line;
    getline(cin, line);

    for(int nr = 1; nr <= cases; nr++){
        getline(cin, line);
        stringstream in(line);

        int aces = 0, amount = 0, count = 0;
        while(amount < 17) {
            count++;

            string next;
            in >> next;

            if(next == "H" || next == "D" || next == "B"){
                amount += 10;
            } else if(next == "1") {
                aces++;
                amount += 11;
            } else {
                amount += stoi(next);
            }

            while(amount > 21 && aces > 0){
                amount -= 10;
                aces--;
            }
        }

        cout << nr << " " << count << " " << amount << endl;
    }
}
