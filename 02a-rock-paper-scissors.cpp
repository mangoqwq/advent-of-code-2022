#include <bits/stdc++.h>

using namespace std;
using ll = long long;

map<char, map<char, int>> mp;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    mp['A'] = {{'X', 3}, {'Y', 6}, {'Z', 0}};
    mp['B'] = {{'X', 0}, {'Y', 3}, {'Z', 6}};
    mp['C'] = {{'X', 6}, {'Y', 0}, {'Z', 3}};
    map<char, int> other = {{'X', 1}, {'Y', 2}, {'Z', 3}};
    string s;
    int ans = 0;
    while (getline(cin, s)){
        char a, b;
        a = s[0], b = s[2];
        ans += mp[a][b] + other[b];
    }
    cout << ans << '\n';
}
