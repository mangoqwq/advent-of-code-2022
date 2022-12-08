#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    vector<string> g;
    string s;
    while (getline(cin, s)){
        g.push_back(s);
    }
    int N = g.size(), M = g[0].size();
    vector<vector<int>> vis(N, vector<int>(M));
    ll ans = 0;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            int d1 = 0;
            for (int k = i-1; k >= 0; --k){
                d1++;
                if (g[k][j] >= g[i][j]) break;
            }
            int d2 = 0;
            for (int k = i+1; k < N; ++k){
                d2++;
                if (g[k][j] >= g[i][j]) break;
            }
            int d3 = 0;
            for (int k = j-1; k >= 0; --k){
                d3++;
                if (g[i][k] >= g[i][j]) break;
            }
            int d4 = 0;
            for (int k = j+1; k < M; ++k){
                d4++;
                if (g[i][k] >= g[i][j]) break;
            }
            ans = max(ans, 1LL * d1 * d2 * d3 * d4);
        }
    }
    cout << ans << '\n';
}
