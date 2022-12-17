#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int memo[20][30][70000];

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    map<string, int> id;
    vector<vector<int>> graph(60);
    vector<int> fid(60), flows;
    struct Edge{ int to, w; };
    vector<vector<Edge>> adj(20);
    set<int> interest;
    int fT = 0, T = 0;
    string line;
    while (getline(cin, line)){
        istringstream iss(line);
        string buf;
        string cur; int f;
        char a, b, c;
        iss >> buf >> cur >> buf >> buf >> c >> c >> c >> c >> c;
        iss >> f >> c >> buf >> buf >> buf >> buf;
        if (!id.count(cur)) id[cur] = T++;
        while (true){
            iss >> a >> b;
            string to = "";
            to += a;
            to += b;
            if (!id.count(to)) id[to] = T++;
            graph[id[cur]].push_back(id[to]);
            if (!(iss >> c)) break;
        }
        if (f || cur == "AA"){
            interest.insert(id[cur]);
            flows.push_back(f);
            fid[id[cur]] = fT++;
        }
    }

    // compress the graph
    for (int src : interest){
        vector<int> dist(60, 1e9);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        while (!q.empty()){
            int v = q.front(); q.pop();
            for (int to : graph[v]){
                if (dist[to] == 1e9){
                    dist[to] = dist[v] + 1;
                    if (interest.count(to)){
                        adj[fid[src]].push_back({fid[to], dist[to]});
                    }
                    q.push(to);
                }
            }
        }
    }

    memset(memo, -1, sizeof memo);
    auto dfs = [&](auto self, int v, int t, int vis) -> int{
        if (t == -1) return 0;
        if (memo[v][t][vis] != -1) return memo[v][t][vis];
        int &ans = memo[v][t][vis];
        ans = 0;
        for (auto [to, w] : adj[v]){
            if (w > t) continue;
            if (1 & (vis >> to)) continue;
            int cont = self(self, to, t-w-1, vis + (1 << to));
            ans = max(ans, cont + (t-w) * flows[to]);
        }
        return ans;
    };

    int src = fid[id["AA"]];
    int best = 0;
    int N = interest.size();
    int all = (1 << N) - 1;
    int time = 26 - 1;
    for (int msk = 0; msk < all; ++msk){
        int me = dfs(dfs, src, time, msk); 
        int ele = dfs(dfs, src, time, all - msk);
        best = max(best, me+ele);
    }
    cout << best << '\n';
}
