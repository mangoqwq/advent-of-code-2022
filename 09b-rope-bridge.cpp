#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    using pii = pair<int, int>;
    map<char, pii> mv = {{'R', {0, 1}}, {'L', {0, -1}}, {'D', {1, 0}}, {'U', {-1, 0}}};
    char dir; int cnt;
    set<pii> seen;
    vector<pii> rope(10, {0, 0});
    seen.insert(rope[9]);
    while (cin >> dir >> cnt){
        for (int x = 0; x < cnt; ++x){
            rope[0].first += mv[dir].first;
            rope[0].second += mv[dir].second;
            for (int i = 1; i < 10; ++i){
                pii &h = rope[i-1];
                pii &t = rope[i];
                if (max(abs(h.first - t.first), abs(h.second - t.second)) == 2){
                    if (abs(h.first - t.first) == 2)
                        t.first = (h.first + t.first) / 2;
                    else
                        t.first = h.first;
                    if (abs(h.second - t.second) == 2)
                        t.second = (h.second + t.second) / 2;
                    else
                        t.second = h.second;
                }
            }
            seen.insert(rope[9]);
        }
    }
    cout << seen.size() << '\n';
}
