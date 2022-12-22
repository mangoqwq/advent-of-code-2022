#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    string line;
    vector<string> g;
    while (getline(cin, line)){
        g.push_back(line);
    }
    string s = g.back();
    g.pop_back();
    g.pop_back();

    int N = g.size();
    int M = 0;
    for (int i = 0; i < N; ++i){
        M = max(M, (int)g[i].size());
    }
    for (int i = 0; i < N; ++i){
        while (g[i].size() < M) g[i] += " ";
    }

    int dir = 0;
    int y = find(g[0].begin(), g[0].end(), '.') - g[0].begin();
    int x = 0;
    auto step = [&]() -> void{
        int sx = x, sy = y;
        do{
            x += dx[dir];
            y += dy[dir];
            x = (x + N) % N;
            y = (y + M) % M;
            if (g[x][y] == '.'){
                sx = x, sy = y;
            }
        } while (g[x][y] == ' ');
        x = sx, y = sy;
    };
    istringstream iss(s);
    int steps; char cd;
    while (iss >> steps){
        cout << x << " " << y << '\n';
        cout.flush();
        for (int i = 0; i < steps; ++i){
            step();
        }
        if (iss >> cd){
            if (cd == 'L') dir = (dir + 3) % 4;
            else dir = (dir + 1) % 4;
        }
    }
    cout << 1000 * (x+1) + 4 * (y+1) + (dir) << '\n';
}
