#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    string s;
    int ans = 0;
    int l, r, l1, r1;
    char c1, c2, c3;
    while (cin >> l >> c1 >> r >> c2 >> l1 >> c3 >> r1){
        if ((l >= l1 && r <= r1) || (l1 >= l && r1 <= r))
            ans++;
    }
    cout << ans << '\n';
}
