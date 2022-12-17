#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<set<pii>> shapes =
{
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    {{1, 0}, {0, 1}, {1, 1}, {1, 2}, {2, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}, {2, 2}},
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {1, 0}, {0, 1}, {1, 1}}
};

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    set<pii> seen;
    string s; cin >> s;
    int height = 0;
    auto insert = [&](pii x){
        seen.insert(x);
        height = max(height, x.second + 1);
    };

    auto good = [&](pii p){
        return p.first >= 0 && p.first < 7 && !seen.count(p) && p.second >= 0;
    };

    auto shift = [&](set<pii> cur, int dx, int dy) -> set<pii>{
        set<pii> nxt;
        for (auto p : cur){
            pii pp = {p.first + dx, p.second + dy};
            if (!good(pp)) return {};
            nxt.insert(pp);
        }
        return nxt;
    };

    int poi = 0;
    for (int i = 0; i < 2022; ++i){
        set<pii> cur;
        int cenx = 2, ceny = height + 3;
        for (pii mould : shapes[i%5]){
            cur.insert({mould.first + cenx, mould.second + ceny});
        }
        while (true){
            set<pii> tmp;
            if (s[poi%s.size()] == '<') tmp = shift(cur, -1, 0);
            if (s[poi%s.size()] == '>') tmp = shift(cur, 1, 0);
            poi++;
            if (!tmp.empty()) cur = tmp;
            tmp = shift(cur, 0, -1);
            if (tmp.empty()){
                for (auto p : cur){
                    insert(p);
                }
                break;
            }
            else cur = tmp;
        }
    }
    cout << height << '\n';
    for (int i = 10; i >= 0; --i){
        for (int x = 0; x < 7; ++x){
            if (seen.count({x, i})) cout << '#';
            else cout << '.';
        }
        cout << '\n';
    }
}
