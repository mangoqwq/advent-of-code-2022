#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    string s; 
    getline(cin, s);
    for (int i = 13; i < s.size(); ++i){
        set<char> se;
        for (int j = i-13; j <= i; ++j){
            se.insert(s[j]);
        }
        if (se.size() == 14){
            cout << i+1 << '\n';
            break;
        }
    }
}
