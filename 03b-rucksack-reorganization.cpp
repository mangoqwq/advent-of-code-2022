#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    string s;
    ll ans = 0;
    while (getline(cin, s)){
        string a, b;
        getline(cin, a);
        getline(cin, b);
        int tot = 0;
        for (int c = 'a'; c <= 'z'; ++c){
            if (a.find(c) != a.npos && b.find(c) != b.npos && s.find(c) != s.npos){
                tot += c - 'a' + 1;
            }
        }
        for (int c = 'A'; c <= 'Z'; ++c){
            if (a.find(c) != a.npos && b.find(c) != b.npos && s.find(c) != s.npos){
                tot += c - 'A' + 27;
            }
        }
        ans += tot;
    }
    cout << ans << '\n';
}
