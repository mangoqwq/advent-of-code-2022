#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll key = 811589153;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    using pii = pair<ll, int>;
    vector<pii> v;
    int x;
    int idx = 0;
    int idx0;
    while (cin >> x){
        if (x == 0) idx0 = idx;
        v.push_back({x * key, idx++});
    }

    int n = v.size();
    vector<pii> ans = v;
    auto pos = [&](pii x){
        return find(ans.begin(), ans.end(), x) - ans.begin();
    };

    // vector<int> utest = v;
    // sort(utest.begin(), utest.end());
    // utest.resize(unique(utest.begin(), utest.end()) - utest.begin());
    // cout << utest.size() << " " << v.size() << '\n';

    for (int it = 0; it < 10; ++it){
        for (pii x : v){
            ll i = pos(x);
            ans.erase(ans.begin() + pos(x));
            i = i + x.first;
            i = (i%(n-1) + (n-1)) % (n-1);
            pii nxt = ans[i];
            ans.insert(ans.begin() + pos(nxt), x);
        }
    }
    ll a = ans[(pos(v[idx0]) + 1000)%n].first;
    ll b = ans[(pos(v[idx0]) + 2000)%n].first;
    ll c = ans[(pos(v[idx0]) + 3000)%n].first;
    cout << a + b + c << '\n';
}
