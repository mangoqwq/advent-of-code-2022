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
    const int SZ = 50;
    auto step = [&]() -> void{
        int sx = x, sy = y, sdir = dir;
        x += dx[dir];
        y += dy[dir];
        x = (x + N) % N;
        y = (y + M) % M;
        /*
        .12
        .3.
        54.
        6..
        */
        if (dir == 1){
            // 4v
            if (x == 3*SZ && y < 2*SZ && y >= 1*SZ){
                dir = 2; // <
                x = (y - 1*SZ) + 3*SZ;
                y = 1*SZ - 1;
            }

            // 2v
            else if (x == 1*SZ && y < 3*SZ && y >= 2*SZ){
                dir = 2;
                x = (y - 2*SZ) + 1*SZ;
                y = 2*SZ - 1;
            }
            // 6v
            else if (x == 0 && y < 1*SZ && y >= 0){
                x = 0;
                y += 2*SZ;
            }
        }

        else if (dir == 3){
            // 5^
            if (x == 2*SZ - 1 && y < 1*SZ && y >= 0){
                dir = 0; // >
                x = (y - 0*SZ) + 1*SZ;
                y = 1*SZ;
            }

            // 1^
            else if (x == 4*SZ - 1 && y < 2*SZ && y >= 1*SZ){
                dir = 0; // >
                x = (y - 1*SZ) + 3*SZ;
                y = 0*SZ;
            }

            // 2^
            else if (x == 4*SZ - 1 && y < 3*SZ && y >= 2*SZ){
                y -= 2*SZ;
            }

        }

        else if (dir == 0){
            // 2>
            if (y == 0 && x < 1*SZ && x >= 0){
                dir = 2; // <
                x = (SZ - (x - 0*SZ) - 1) + 2*SZ;
                y = 2*SZ - 1;
            }

            // 3>
            else if (y == 2*SZ && x < 2*SZ && x >= 1*SZ){
                dir = 3; // ^
                y = (x - 1*SZ) + 2*SZ;
                x = 1*SZ - 1;
            }

            // 4>
            else if (y == 2*SZ && x < 3*SZ && x >= 2*SZ){
                dir = 2; // <
                x = (SZ - (x - 2*SZ) - 1) + 0*SZ;
                y = 3*SZ - 1;
            }

            // 6>
            else if (y == 1*SZ && x < 4*SZ && x >= 3*SZ){
                dir = 3; // ^
                y = (x - 3*SZ) + 1*SZ;
                x = 3*SZ-1;
            }
        }

        else if (dir == 2){
            // 6< -> (top of 1)
            if (y == 3*SZ - 1 && x < 4*SZ && x >= 3*SZ){
                dir = 1; // v
                y = (x - 3*SZ) + 1*SZ;
                x = 0;
            }

            // 5< -> (left of 1, flipped)
            else if (y == 3*SZ - 1 && x < 3*SZ && x >= 2*SZ){
                dir = 0; // >
                x = (SZ - (x - 2*SZ) - 1) + 0*SZ;
                y = 1*SZ;
            }

            // 3< -> (top of 5)
            else if (y == 1*SZ - 1 && x < 2*SZ && x >= 1*SZ){
                dir = 1; // v
                y = (x - 1*SZ) + 0*SZ;
                x = 2*SZ;
            }

            // 1< -> (left of 5, flipped)
            else if (y == 1*SZ - 1 && x < 1*SZ && x >= 0){
                dir = 0; // v
                x = (SZ - (x - 0*SZ) - 1) + 2*SZ;
                y = 0;
            }

        }

        if (g[x][y] == ' '){
            cout << sx << " " << sy << " " << sdir << " | " << x << " " << y << " " << dir << '\n';
            cout.flush();
        }
        assert(g[x][y] != ' ');
        if (g[x][y] != '#'){
            sx = x, sy = y, sdir = dir;
        }
        x = sx, y = sy, dir = sdir;
    };
    istringstream iss(s);
    int steps; char cd;
    while (iss >> steps){
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
