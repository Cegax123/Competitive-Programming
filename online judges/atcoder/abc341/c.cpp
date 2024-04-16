#include<bits/stdc++.h>
using namespace std;

int main() {
    int h, w; cin >> h >> w;
    int n; cin >> n;
    string dir; cin >> dir;


    vector<pair<int, int>> pos;
    pair<int, int> curr = {0, 0};
    pos.push_back(curr);

    for(char c : dir) {
        if(c == 'L') curr.second--;
        else if(c == 'R') curr.second++;
        else if(c == 'U') curr.first--;
        else curr.first++;

        pos.push_back(curr);
    }

    string s[h];

    for(int i = 0; i < h; i++) cin >> s[i];


    int cnt = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            bool cmp = true;

            for(auto mov : pos) {
                int nx = i + mov.first, ny = j + mov.second;
                if(s[nx][ny] == '#') {
                    cmp = false;
                    break;
                }
            }

            if(cmp) cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}
