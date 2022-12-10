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
        if ((cy-20) % 40 == 0) tot += cur * cy;
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
    cout << tot << '\n';
}
