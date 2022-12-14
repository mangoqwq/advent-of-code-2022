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
    ll ans = 0;
    while (true){
        int x = 500, y = 0;
        while (y < 1000){
            if (!b.count({x, y+1})){
                y++;
            }
            else if (!b.count({x-1, y+1})){
                y++, x--;
            }
            else if (!b.count({x+1, y+1})){
                y++, x++;
            }
            else break;
        }
        if (y >= 1000){
            break;
        }
        ans++;
        b.insert({x, y});
    }
    cout << ans << '\n';
}
