#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    string s;
    ll mx = 0, cur = 0;
    while (getline(cin, s)){
        if (s == "") mx = max(mx, cur), cur = 0;
        else cur += stoi(s);
    }
    cout << mx << '\n';
}
