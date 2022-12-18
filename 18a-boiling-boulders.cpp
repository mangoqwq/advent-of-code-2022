#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    string s;
    struct Item{
        int x, y, z;
        bool operator<(const Item &other) const{
            return tie(x,y,z) < tie(other.x, other.y, other.z);
        }
    };
    set<Item> se;
    char c;
    int x, y, z;
    while (cin >> x >> c >> y >> c >> z){
        se.insert({x, y, z});
    }
    int ans = 0;
    for (auto [x, y, z] : se){
        if (!se.count({x-1,y,z})) ans++;
        if (!se.count({x+1,y,z})) ans++;
        if (!se.count({x,y-1,z})) ans++;
        if (!se.count({x,y+1,z})) ans++;
        if (!se.count({x,y,z-1})) ans++;
        if (!se.count({x,y,z+1})) ans++;
    }
    cout << ans << '\n';
}
