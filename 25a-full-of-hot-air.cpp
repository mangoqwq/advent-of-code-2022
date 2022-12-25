#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    vector<ll> p5(26);
    vector<ll> mx(26);
    p5[0] = 1;
    mx[0] = 2;
    for (int i = 1; i <= 25; ++i){
        p5[i] = p5[i-1] * 5;
        mx[i] = mx[i-1] + p5[i] * 2;
    }

    ll tot = 0;
    string line;
    while (getline(cin, line)){
        reverse(line.begin(), line.end());
        ll cur = 0;
        for (int i = 0; i < line.size(); ++i){
            if (line[i] == '=') cur -= 2 * p5[i];
            if (line[i] == '-') cur -= 1 * p5[i];
            if (line[i] == '0') cur += 0 * p5[i];
            if (line[i] == '1') cur += 1 * p5[i];
            if (line[i] == '2') cur += 2 * p5[i];
        }
        tot += cur;
    }

    const char arr[] = {'=', '-', '0', '1', '2'};

    bool good = 0;
    string ans = "";
    ll cur = 0;
    for (int i = 25; i >= 1; --i){
        for (int j = -2; j <= 2; ++j){
            if (cur + j * p5[i] + mx[i-1] >= tot){
                ans += arr[j + 2];
                cur += j * p5[i];
                break;
            }
        }
    }
    ans += arr[tot - cur + 2];
    while (ans.front() == '0') ans.erase(ans.begin());
    cout << ans << '\n';
}
