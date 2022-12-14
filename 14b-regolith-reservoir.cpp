#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    using pii = pair<int, int>;
    set<pii> b;
    string s;
    while (getline(cin, s)){
        istringstream iss;
        iss.str(s);
        char c;
        int x, y; iss >> x >> c >>  y;
        int nx, ny;
        string buf;
        while (iss >> buf >> nx >> c >> ny){
            for (int i = min(x, nx); i <= max(x, nx); ++i){
                for (int j = min(y, ny); j <= max(y, ny); ++j){
                    b.insert({i, j});
                }
            }
            x = nx, y = ny;
        }
    }
    int floor = 0;
    for (auto [x, y] : b){
        floor = max(floor, y + 2);
    }
    ll ans = 1;
    set<int> sand;
    sand.insert(500);
    for (int i = 1; i < floor; ++i){
        set<int> nxt;
        for (int x : sand){
            if (!b.count({x-1, i})) nxt.insert(x-1);
            if (!b.count({x, i})) nxt.insert(x);
            if (!b.count({x+1, i})) nxt.insert(x+1);
        }
        ans += nxt.size();
        swap(sand, nxt);
    }
    cout << ans << '\n';
}
