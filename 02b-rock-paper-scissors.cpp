#include <bits/stdc++.h>

using namespace std;
using ll = long long;

map<char, map<char, char>> mp;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    map<char, int> res = {{'X', 0}, {'Y', 3}, {'Z', 6}};
    mp['A'] = {{'X', 'Z'}, {'Y', 'X'}, {'Z', 'Y'}};
    mp['B'] = {{'X', 'X'}, {'Y', 'Y'}, {'Z', 'Z'}};
    mp['C'] = {{'X', 'Y'}, {'Y', 'Z'}, {'Z', 'X'}};
    map<char, int> other = {{'X', 1}, {'Y', 2}, {'Z', 3}};
    string s;
    int ans = 0;
    while (getline(cin, s)){
        char a, b;
        a = s[0], b = s[2];
        ans += res[b] + other[mp[a][b]];
    }
    cout << ans << '\n';
}
