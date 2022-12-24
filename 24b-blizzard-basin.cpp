#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    vector<string> g;
    string s;
    while (getline(cin, s)){
        g.push_back(s);
    }

    int N = g.size(), M = g[0].size();
    auto in = [&](int i, int j){
        return i >= 0 && i < N && j >= 0 && j < M;
    };
    
    vector<vector<vector<int>>> bads(N, vector<vector<int>>(M));
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            if (g[i][j] == '>') bads[i][j].push_back(0);
            if (g[i][j] == 'v') bads[i][j].push_back(1);
            if (g[i][j] == '<') bads[i][j].push_back(2);
            if (g[i][j] == '^') bads[i][j].push_back(3);
        }
    }
    vector<vector<vector<int>>> can(N, vector<vector<int>>(M, vector<int>(3)));
    can[0][1][0] = 1;
    for (int mov = 1; ; ++mov){
        vector<vector<vector<int>>> nxtbads(N, vector<vector<int>>(M));
        vector<vector<vector<int>>> nxtcan(N, vector<vector<int>>(M, vector<int>(3)));
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < M; ++j){
                for (auto d : bads[i][j]){
                    int nx = i + dx[d], ny = j + dy[d];
                    if (nx == N-1) nx = 1;
                    if (nx == 0) nx = N-2;
                    if (ny == M-1) ny = 1;
                    if (ny == 0) ny = M-2;
                    nxtbads[nx][ny].push_back(d);
                }
            }
        }
        bads = nxtbads;
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < M; ++j){
                for (int x = 0; x < 3; ++x){
                    if (!can[i][j][x]) continue;
                    for (int d = 0; d < 4; ++d){
                        int nx = i + dx[d], ny = j + dy[d];
                        if (!in(nx, ny)) continue;
                        if (g[nx][ny] != '#' && bads[nx][ny].empty()){
                            nxtcan[nx][ny][x] = 1;
                        }
                    }
                    if (bads[i][j].empty()) nxtcan[i][j][x] = 1;
                }
            }
        }
        can = nxtcan;
        if (can[N-1][M-2][0]) can[N-1][M-2][1] = 1;
        if (can[0][1][1]) can[0][1][2] = 1;
        if (can[N-1][M-2][2]){
            cout << mov << '\n';
            break;
        }
    }
}
