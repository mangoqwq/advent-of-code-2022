#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    string line;
    map<string, int> deg;
    map<string, vector<string>> adj;
    map<string, string> ops;
    map<string, ll> val;
    map<string, string> froma;
    map<string, string> fromb;
    queue<string> q;
    while (getline(cin, line)){
        istringstream iss(line);
        string name; iss >> name;
        name = name.substr(0, 4);
        if (line[6] >= '0' && line[6] <= '9'){
            int x; iss >> x;
            val[name] = x;
            q.push(name);
        }
        else{
            string a, op, b;
            iss >> a >> op >> b;
            ops[name] = op;
            adj[a].push_back(name);
            adj[b].push_back(name);
            froma[name] = a;
            fromb[name] = b;
            deg[name] = 2;
        }
    }
    while (!q.empty()){
        string v = q.front(); q.pop();
        if (!val.count(v)){
            if (ops[v] == "+"){
                val[v] = val[froma[v]] + val[fromb[v]];
            }
            if (ops[v] == "-"){
                val[v] = val[froma[v]] - val[fromb[v]];
            }
            if (ops[v] == "*"){
                val[v] = val[froma[v]] * val[fromb[v]];
            }
            if (ops[v] == "/"){
                val[v] = val[froma[v]] / val[fromb[v]];
            }
        }
        for (string to : adj[v]){
            deg[to]--;
            if (deg[to] == 0){
                q.push(to);
            }
        }
    }
    cout << val["root"] << '\n';
}
