#include <bits/stdc++.h>

/*

part 2: guess that the rock pattern eventually becomes periodic
find the period by searching for a specific pattern
turns out the rock pattern repeats every 1695 rocks

find two points equal to 1000000000000 modulo 1695
extrapolate the height at 1000000000000 using the line that goes through these points

pattern height rocks
..###.. 609706 392351
...#... 609705 392351
.####.. 609704 392350 !!!
....##. 609703 392349
....##. 609702 392349

..###.. 612340 394046
...#... 612339 394046
.####.. 612338 394045 !!!
....##. 612337 394044
....##. 612336 394044

(1000000000000 - 392350) / 1695 * (612338 - 609704) + 609704
*/


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
    map<int, int> latest;
    string s; cin >> s;
    int height = 0, T = 0;
    auto insert = [&](pii x){
        seen.insert(x);
        height = max(height, x.second + 1);
        latest[x.second] = T;
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
    for (int i = 0; i < 400000; ++i){
        T = i;
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
    for (int i = height+10; i >= 0; --i){
        for (int x = 0; x < 7; ++x){
            if (seen.count({x, i})) cout << '#';
            else cout << '.';
        }
        cout << " " << i << " " << latest[i];
        cout << '\n';
    }
}
