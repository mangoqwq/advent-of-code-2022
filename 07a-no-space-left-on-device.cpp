#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    auto shrink = [&](vector<string> vec){
        string s = "/";
        for (string c : vec) s += c + "/";
        return s;
    };
    string line;

    map<string, vector<string>> adj;
    map<string, ll> sz;
    map<string, ll> val;
    vector<string> cur;
    while (getline(cin, line)){
        istringstream iss;
        iss.str(line);
        string op; iss >> op;
        if (op == "$"){
            string cmd; iss >> cmd;
            if (cmd == "ls"){
                continue;
            }
            else{
                string nxt; iss >> nxt;
                if (nxt == "/") cur.clear();
                else if (nxt == "..") cur.pop_back();
                else cur.push_back(nxt);
            }
        }
        else{
            if (op == "dir"){
                string nxt; iss >> nxt;
                string now = shrink(cur);
                cur.push_back(nxt);

                adj[now].push_back(shrink(cur));
                cur.pop_back();
            }
            else{
                string file; iss >> file;
                val[shrink(cur)] += stoi(op);
            }
        }
    }

    ll ans = 0;
    auto dfs = [&](auto self, string s) -> ll{
        sz[s] = val[s];
        for (string to : adj[s]){
            sz[s] += self(self, to);
        }
        if (sz[s] <= 100000) ans += sz[s];
        return sz[s];
    };
    dfs(dfs, "/");
    cout << ans << '\n';
}
