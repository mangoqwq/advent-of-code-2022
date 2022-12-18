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
    multiset<Item> could;
    for (auto [x, y, z] : se){
        if (!se.count({x-1,y,z})) could.insert({x-1,y,z});
        if (!se.count({x+1,y,z})) could.insert({x+1,y,z});
        if (!se.count({x,y-1,z})) could.insert({x,y-1,z});
        if (!se.count({x,y+1,z})) could.insert({x,y+1,z});
        if (!se.count({x,y,z-1})) could.insert({x,y,z-1});
        if (!se.count({x,y,z+1})) could.insert({x,y,z+1});
    }
    for (auto [sx, sy, sz] : could){
        set<Item> seen;
        seen.insert({sx, sy, sz});
        queue<Item> q;
        q.push({sx, sy, sz});
        while (!q.empty() && seen.size() <= 5000){
            auto [x, y, z] = q.front(); q.pop();
            if (!se.count({x-1,y,z}) && !seen.count({x-1,y,z})){
                seen.insert({x-1,y,z});
                q.push({x-1,y,z});
            }
            if (!se.count({x+1,y,z}) && !seen.count({x+1,y,z})){
                seen.insert({x+1,y,z});
                q.push({x+1,y,z});
            }
            if (!se.count({x,y-1,z}) && !seen.count({x,y-1,z})){
                seen.insert({x,y-1,z});
                q.push({x,y-1,z});
            }
            if (!se.count({x,y+1,z}) && !seen.count({x,y+1,z})){
                seen.insert({x,y+1,z});
                q.push({x,y+1,z});
            }
            if (!se.count({x,y,z-1}) && !seen.count({x,y,z-1})){
                seen.insert({x,y,z-1});
                q.push({x,y,z-1});
            }
            if (!se.count({x,y,z+1}) && !seen.count({x,y,z+1})){
                seen.insert({x,y,z+1});
                q.push({x,y,z+1});
            }
        }
        if (seen.size() > 5000){
            ans++;
        }
    }
    cout << ans << '\n';
}
