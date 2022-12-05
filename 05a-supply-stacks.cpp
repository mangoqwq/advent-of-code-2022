#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<string> stk = {
    "BGSC",
    "TMWHJNVG",
    "MQS",
    "BSLTWNM",
    "JZFTVGWP",
    "CTBGQHS",
    "TJPBW",
    "GDCZFTQM",
    "NSHBPF"
};

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    string s0, s1, s2;
    int a, b, c;
    while (cin >> s0 >> a >> s1 >> b >> s2 >> c){
        b--; c--;
        for (int i = 0; i < a; ++i){
            stk[c].push_back(stk[b].back());
            stk[b].pop_back();
        }
    }
    string ans = "";
    for (int i = 0; i < stk.size(); ++i){
        if (!stk[i].empty()){
            ans += stk[i].back();
        }
    }
    cout << ans << '\n';
}
