#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<vector<pii>> dirs = 
{
    {{-1, 0}, {-1, 1}, {-1, -1}},
    {{1, 0}, {1, 1}, {1, -1}},
    {{0, -1}, {-1, -1}, {1, -1}},
    {{0, 1}, {-1, 1}, {1, 1}}
};

int B = 10;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    vector<string> g;
    string line;
    while (getline(cin, line)){
        g.push_back(line);
    }
    int N = g.size() + B * 2;
    int M = g[0].size() + B * 2;
    for (auto &s : g){
        s = string(B, '.') + s + string(B, '.');
    }
    for (int i = 0; i < B; ++i){
        g.insert(g.begin(), string(M, '.'));
        g.push_back(string(M, '.'));
    }
    auto in = [&](int x, int y){
        return x >= 0 && x < N && y >= 0 && y < M;
    };
    for (int it = 0; it < 10; ++it){
        vector<vector<int>> cnt(N, vector<int>(M));
        vector<vector<int>> mov(N, vector<int>(M));
        vector<string> nxt(N);
        for (int i = 0; i < N; ++i){
            nxt[i] = string(M, '.');
        }
        for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j){
            if (g[i][j] == '.') continue;
            bool lone = 1;
            for (int dx = -1; dx <= 1; ++dx){
                for (int dy = -1; dy <= 1; ++dy){
                    if (dx == 0 && dy == 0) continue;
                    int nx = i + dx, ny = j + dy;
                    if (in(nx, ny)){
                        lone &= g[nx][ny] == '.';
                    }
                }
            }
            if (lone) continue;
            for (int d = 0; d < 4; ++d){
                bool good = 1;
                for (int k = 0; k < 3; ++k){
                    int nx = i + dirs[d][k].first;
                    int ny = j + dirs[d][k].second;
                    if (!in(nx, ny)){ good = 0; break; }
                    if (g[nx][ny] == '#') good = 0;
                }
                int nx = i + dirs[d][0].first;
                int ny = j + dirs[d][0].second;
                if (good){
                    cnt[nx][ny]++;
                    mov[i][j] = d + 1;
                    break;
                }
            }
        }

        for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j){
            if (g[i][j] == '.') continue;
            if (mov[i][j] == 0) nxt[i][j] = '#';
            else{
                int d = mov[i][j] - 1;
                int nx = i + dirs[d][0].first;
                int ny = j + dirs[d][0].second;
                if (cnt[nx][ny] == 1) nxt[nx][ny] = '#';
                else nxt[i][j] = '#';
            }
        }

        g = nxt;

        dirs.push_back(dirs[0]);
        dirs.erase(dirs.begin());
    }

    int mnx = N, mxx = 0, mny = M, mxy = 0, cnt = 0;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j){
        if (g[i][j] == '#'){
            cnt++;
            mnx = min(mnx, i);
            mxx = max(mxx, i);
            mny = min(mny, j);
            mxy = max(mxy, j);
        }
    }
    cout << (mxy - mny + 1) * (mxx - mnx + 1) - cnt << '\n';
}
