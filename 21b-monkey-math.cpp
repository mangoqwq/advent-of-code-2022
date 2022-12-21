#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    string line;
    map<string, int> deg_o;
    map<string, vector<string>> adj;
    map<string, string> ops;
    map<string, ll> val_o;
    map<string, string> froma;
    map<string, string> fromb;
    queue<string> q_o;
    while (getline(cin, line)){
        istringstream iss(line);
        string name; iss >> name;
        name = name.substr(0, 4);
        if (line[6] >= '0' && line[6] <= '9'){
            ll x; iss >> x;
            val_o[name] = x;
            q_o.push(name);
        }
        else{
            string a, op, b;
            iss >> a >> op >> b;
            ops[name] = op;
            adj[a].push_back(name);
            adj[b].push_back(name);
            froma[name] = a;
            fromb[name] = b;
            deg_o[name] = 2;
        }
    }
    ll lo = 0, hi = 5615010794218;
    while (lo < hi){
        ll guess = (lo + hi) >> 1;
        auto q = q_o;
        map<string, ll> val = val_o;
        map<string, int> deg = deg_o;
        val["humn"] = guess;
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
        cout << guess << " " << val["jsrw"] << " " << val["ptvl"] << '\n';
        cout.flush();
        if (val["jsrw"] >= val["ptvl"]){
            lo = guess + 1;
        }
        else{
            hi = guess;
        }
    }
    cout << lo << '\n';
}
