#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    string s;
    int cy = 0;
    int tot = 0, cur = 1;
    auto step = [&](){
        cy++;
        int y = (cy - 1) % 40;
        if (abs(y - cur) <= 1) cout << '#';
        else cout << '.';
        if (cy % 40 == 0) cout << '\n';
    };
    while (cin >> s){
        if (s == "addx"){
            int vx; cin >> vx;
            step();
            step();
            cur += vx;
        }
        else{
            step();
        }
    }
}
