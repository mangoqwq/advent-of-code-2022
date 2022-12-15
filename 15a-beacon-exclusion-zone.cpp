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
    int iy = 2000000;
    int ans = 0;
    for (int ix = -8000000; ix <= 8000000; ++ix){
        bool bad = 0;
        for (auto [x, y, d] : vec){
            if (abs(x-ix) + abs(y-iy) <= d) bad = 1;
        }
        if (beacons.count({ix, iy})) bad = 0;
        ans += bad;
    }
    cout << ans << '\n';
}
