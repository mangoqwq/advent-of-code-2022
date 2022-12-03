#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    string s;
    ll ans = 0;
    while (getline(cin, s)){
        int n = s.size() / 2;
        string a = s.substr(0, n);
        string b = s.substr(n);
        for (int c = 'a'; c <= 'z'; ++c){
            if (a.find(c) != a.npos && b.find(c) != b.npos){
                ans += c - 'a' + 1;
            }
        }
        for (int c = 'A'; c <= 'Z'; ++c){
            if (a.find(c) != a.npos && b.find(c) != b.npos){
                ans += c - 'A' + 27;
            }
        }
    }
    cout << ans << '\n';
}
