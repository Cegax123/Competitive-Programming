#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s, t; cin >> s >> t;

    int n = s.size();
    int lft[n], rgt[n];

    int curr = 0;
    for(int i = 0; i < n; i++) {
        lft[i] = curr;
        if(curr < (int) t.size() and t[curr] == s[i]) {
            curr++;
        }
    }

    curr = (int) t.size()-1;
    for(int i = n-1; i >= 0; i--) {
        rgt[i] = (int) t.size()-1-curr;
        if(curr >= 0 and t[curr] == s[i]) {
            curr--;
        }
    }

    const int E = 26;
    vector<int> pos[E];

    for(int i = 0; i < (int) t.size(); i++) {
        pos[t[i]-'a'].push_back(i);
    }

    bool cmp = 1;
    for(int i = 0; i < (int) s.size(); i++) {
        int x = s[i]-'a';
        if(pos[x].empty()) {
            cmp = 0;
            break;
        }

        int l = 0, r = (int) pos[x].size()-1;

        while(l < r) {
            int m = (l+r+1) >> 1;
            if(pos[x][m] <= lft[i]) l = m;
            else r = m-1;
        }

        //cout << i << " " << pos[x][l] << " " << lft[i] << endl;

        if(pos[x][l] <= lft[i]) {
            //cout << "HOLA\n";
            int px = pos[x][l];
            if(px+1+rgt[i] < (int) t.size()) cmp = 0;
        }
        else {
            cmp = 0;
            break;
        }
    }

    cout << (cmp ? "Yes\n" : "No\n");

    return 0;
}
