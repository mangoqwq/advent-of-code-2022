#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    string s;
    ll mx = 0, cur = 0;
    vector<int> a;
    while (getline(cin, s)){
        if (s == "") a.push_back(cur), cur = 0;
        else cur += stoi(s);
    }
    sort(a.begin(), a.end(), greater<int>());
    cout << a[0] + a[1] + a[2] << '\n';
}
