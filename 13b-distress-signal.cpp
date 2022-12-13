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
    vector<string> vec;
    while (getline(cin, a)){
        getline(cin, b);
        string filler; getline(cin, filler);
        vec.push_back(a);
        vec.push_back(b);
    }
    vec.push_back("[[2]]");
    vec.push_back("[[6]]");
    sort(vec.begin(), vec.end(), [&](string a, string b){
        return (leq(leq, a, b)) < 0;
    });
    int i = find(vec.begin(), vec.end(), "[[2]]") - vec.begin() + 1;
    int j = find(vec.begin(), vec.end(), "[[6]]") - vec.begin() + 1;
    cout << i*j << '\n';
}
