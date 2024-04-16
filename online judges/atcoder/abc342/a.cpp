#include<bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    map<char, int> cnt;

    for(char c : s) cnt[c]++;

    char ans;

    for(auto e : cnt) {
        if(e.second == 1) {
            ans = e.first;
        }
    }

    for(int i = 0; i < (int) s.size(); i++) {
        if(ans == s[i]) {
            cout << i+1 << "\n";
        }
    }

    return 0;
}
