#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    vector<string> g;
    string s;
    while (cin >> s){
        g.push_back(s);
    }
    int N = g.size(), M = g[0].size();
    int sx, sy, ex, ey;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            if (g[i][j] == 'S') sx = i, sy = j;
            if (g[i][j] == 'E') ex = i, ey = j;
        }
    }
    auto in = [&](int i, int j){
        return i >= 0 && i < N && j >= 0 && j < M;
    };
    g[sx][sy] = 'a';
    g[ex][ey] = 'z';
    vector<vector<int>> dist(N, vector<int>(M, 1e9));
    dist[sx][sy] = 0;
    using pii = pair<int, int>;
    queue<pii> q;
    q.push({sx, sy});
    while (!q.empty()){
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; ++i){
            int nx = x + dx[i], ny = y + dy[i];
            if (!in(nx, ny)) continue;
            if (g[nx][ny] <= g[x][y] + 1){
                if (dist[nx][ny] > dist[x][y] + 1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << dist[ex][ey] << '\n';
}
