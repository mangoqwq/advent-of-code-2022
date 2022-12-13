#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    string a, b;
    int idx = 1;

    auto split = [&](string a) -> vector<string>{
        vector<string> ret;
        string cur; int cnt = 0;
        for (int i = 1; i < a.size()-1; ++i){
            if (a[i] == '[') cnt++;
            if (a[i] == ']') cnt--;
            if (!cnt && a[i] == ',') ret.push_back(cur), cur = "";
            else cur += a[i];
        }
        if (cur != "") ret.push_back(cur);
        return ret;
    };

    auto leq = [&](auto self, string a, string b) -> int{
        if (a.empty()) return -1;
        if (b.empty()) return 1;
        bool ba = 0, bb = 0;
        if (a[0] == '[' && a.back() == ']') ba = 1;
        if (b[0] == '[' && b.back() == ']') bb = 1;
        if (ba || bb){
            if (!ba) a = "[" + a + "]";
            if (!bb) b = "[" + b + "]";
            vector<string> nxta = split(a);
            vector<string> nxtb = split(b);
            for (int i = 0; i < min(nxta.size(), nxtb.size()); ++i){
                int ret = self(self, nxta[i], nxtb[i]);
                if (ret) return ret;
            }
            if (nxta.size() < nxtb.size()) return -1;
            if (nxta.size() > nxtb.size()) return 1;
            return 0;
        }
        else{
            if (stoi(a) < stoi(b)) return -1;
            if (stoi(a) > stoi(b)) return 1;
            return 0;
        }
    };
    int ans = 0;
    while (getline(cin, a)){
        getline(cin, b);
        string filler; getline(cin, filler);
        int ret = leq(leq, a, b);
        if (ret <= 0) ans += idx;
        idx++;
    }
    cout << ans << '\n';
}
