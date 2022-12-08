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
    int ans = 0;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            bool good = 1;
            for (int k = i-1; k >= 0; --k){
                if (g[k][j] >= g[i][j]) good = 0;
            }
            if (good) vis[i][j] = 1;
            good = 1;
            for (int k = i+1; k < N; ++k){
                if (g[k][j] >= g[i][j]) good = 0;
            }
            if (good) vis[i][j] = 1;
            good = 1;
            for (int k = j-1; k >= 0; --k){
                if (g[i][k] >= g[i][j]) good = 0;
            }
            if (good) vis[i][j] = 1;
            good = 1;
            for (int k = j+1; k < M; ++k){
                if (g[i][k] >= g[i][j]) good = 0;
            }
            if (good) vis[i][j] = 1;
            if (vis[i][j]) ans ++;
        }
    }
    cout << ans << '\n';
}
