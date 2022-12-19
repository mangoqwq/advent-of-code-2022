#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct State{
    int ore, clay, obi, geo;
    bool operator<(const State &o) const{
        return tie(ore, clay, obi) < tie(o.ore, o.clay, o.obi);
    }
};

const int L = 24;
const int M1 = 4;
const int M2 = 20;
const int M3 = 15;
const int M4 = L;
map<State, int> dp[L+1][M1+1][M2+1][M3+1][M4+1];

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    string line;
    ll ans = 0;
    while (getline(cin, line)){
        istringstream iss(line);
        string b;
        int id;
        // 1 makes ore
        // 2 makes clay
        // 3 makes obi
        // 4 makes geode
        int c1ore, c2ore, c3ore, c3clay, c4ore, c4obi;
        iss >> b >> id >> b;
        iss >> b >> b >> b >> b >> c1ore >> b;
        iss >> b >> b >> b >> b >> c2ore >> b;
        iss >> b >> b >> b >> b >> c3ore >> b >> b >> c3clay >> b;
        iss >> b >> b >> b >> b >> c4ore >> b >> b >> c4obi >> b;

        for (int i = 0; i <= L; ++i)
            for (int j = 0; j <= M1; ++j)
                for (int k = 0; k <= M2; ++k)
                    for (int l = 0; l <= M3; ++l)
                        for (int m = 0; m <= M4; ++m)
                            dp[i][j][k][l][m].clear();
        
        auto dfs = [&](auto self, int t, int c1, int c2, int c3, int c4, int ore, int clay, int obi, int geo) -> int{
            // int mxore = (t) * max({c1ore, c2ore, c3ore, c4ore});
            // int mxclay = (t) * c3clay;
            // int mxobi = (t) * c4obi;
            // ore = min(ore, mxore);
            // clay = min(clay, mxclay);
            // obi = min(obi, mxobi);
            if (ore >= 30) ore = 30;
            if (clay >= 40) clay = 40;
            if (c1 > M1) return 0;
            if (c2 > M2) return 0;
            if (c3 > M3) return 0;
            if (c4 > M4) return 0;
            if (t == 0){
                // cout << ore << " " << clay << " " << obi << " " << geo << '\n';
                return geo;
            }
            State state = {ore, clay, obi};
            if (dp[t][c1][c2][c3][c4].count(state)) return dp[t][c1][c2][c3][c4][state];
            int &cur = dp[t][c1][c2][c3][c4][state];

            if (c1ore <= ore){
                cur = max(cur, self(self, t-1, c1+1, c2, c3, c4, ore+c1-c1ore, clay+c2, obi+c3, geo+c4));
            }

            if (c2ore <= ore){
                cur = max(cur, self(self, t-1, c1, c2+1, c3, c4, ore+c1-c2ore, clay+c2, obi+c3, geo+c4));
            }

            if (c3ore <= ore && c3clay <= clay){
                cur = max(cur, self(self, t-1, c1, c2, c3+1, c4, ore+c1-c3ore, clay+c2-c3clay, obi+c3, geo+c4));
            }

            if (c4ore <= ore && c4obi <= obi){
                cur = max(cur, self(self, t-1, c1, c2, c3, c4+1, ore+c1-c4ore, clay+c2, obi+c3-c4obi, geo+c4));
            }

            cur = max(cur, self(self, t-1, c1, c2, c3, c4, ore+c1, clay+c2, obi+c3, geo+c4));
            return cur;
        };
        int best = dfs(dfs, L, 1, 0, 0, 0, 0, 0, 0, 0);
        cout << best << " ";
        cout.flush();
        ans += best * id;
    }
    cout << ans << '\n';
}
