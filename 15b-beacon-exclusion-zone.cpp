#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    string line;
    struct Beacon{ ll x, y, d; };
    vector<Beacon> vec;
    using pii = pair<int, int>;
    set<pii> beacons;
    while(getline(cin, line)){
        istringstream iss(line);
        string buf; char c;
        ll x, y, cx, cy;
        iss >> buf >> buf >> c >> c >> x;
        iss >> c >> c >> c >> y >> c >> buf >> buf >> buf >> buf;
        iss >> c >> c >> cx >> c >> c >> c >> cy;
        vec.push_back({x, y, abs(x-cx) + abs(y-cy)});
        beacons.insert({cx, cy});
    }
    for (int i = 0; i <= 4000000; ++i){
        vector<pii> ints;
        for (auto [x, y, d] : vec){
            int del = d - abs(i-x);
            if (del >= 0){
                ints.push_back({y-del, y+del});
            }
        }
        sort(ints.begin(), ints.end());
        int lst = 0;
        for (auto [a, b] : ints){
            if (a > lst){
                cout << i * 4000000LL + (a-1) << '\n';
                return 0;
            }
            lst = max(lst, b);
        }
    }
}
