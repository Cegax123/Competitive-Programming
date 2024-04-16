#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        string b[3];
        map<char, int> cnt;
        for(int i = 0; i < 3; i++) {
            cin >> b[i];
            for(char c : b[i]) cnt[c]++;
        }

        for(auto e : cnt) {
            if(e.second == 2) cout << e.first << "\n";
        }
    }


    return 0;
}
