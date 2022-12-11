#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 9699690;

vector<vector<ll>> items =
{
    {63, 84, 80, 83, 84, 53, 88, 72},
    {67, 56, 92, 88, 84},
    {52},
    {59, 53, 60, 92, 69, 72},
    {61, 52, 55, 61},
    {79, 53},
    {59, 86, 67, 95, 92, 77, 91},
    {58, 83, 89}
};

vector<vector<ll>> to =
{
    {4, 7},
    {5, 3},
    {3, 1},
    {5, 6},
    {7, 2},
    {0, 6},
    {4, 0},
    {2, 1}
};

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    vector<ll> cnt(8);
    for (int _ = 0; _ < 10000; ++_){
        for (int i = 0; i < 8; ++i){
            for (ll x : items[i]){
                cnt[i]++;
                if (i == 0){
                    ll y = (x * 11) % mod;
                    if (y % 13 == 0){
                        items[to[i][0]].push_back(y);
                    } else{
                        items[to[i][1]].push_back(y);
                    }
                }
                if (i == 1){
                    ll y = (x + 4) % mod;
                    if (y % 11 == 0){
                        items[to[i][0]].push_back(y);
                    } else{
                        items[to[i][1]].push_back(y);
                    }
                }
                if (i == 2){
                    ll y = (x * x) % mod;
                    if (y % 2 == 0){
                        items[to[i][0]].push_back(y);
                    } else{
                        items[to[i][1]].push_back(y);
                    }
                }
                if (i == 3){
                    ll y = (x + 2) % mod;
                    if (y % 5 == 0){
                        items[to[i][0]].push_back(y);
                    } else{
                        items[to[i][1]].push_back(y);
                    }
                }
                if (i == 4){
                    ll y = (x + 3) % mod;
                    if (y % 7 == 0){
                        items[to[i][0]].push_back(y);
                    } else{
                        items[to[i][1]].push_back(y);
                    }
                }
                if (i == 5){
                    ll y = (x + 1) % mod;
                    if (y % 3 == 0){
                        items[to[i][0]].push_back(y);
                    } else{
                        items[to[i][1]].push_back(y);
                    }
                }
                if (i == 6){
                    ll y = (x + 5) % mod;
                    if (y % 19 == 0){
                        items[to[i][0]].push_back(y);
                    } else{
                        items[to[i][1]].push_back(y);
                    }
                }
                if (i == 7){
                    ll y = (x * 19) % mod;
                    if (y % 17 == 0){
                        items[to[i][0]].push_back(y);
                    } else{
                        items[to[i][1]].push_back(y);
                    }
                }
            }
            items[i].clear();
        }
    }
    sort(cnt.begin(), cnt.end());
    for (ll x : cnt) cout << x << " ";
}
