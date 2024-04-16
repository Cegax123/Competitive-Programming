#include<bits/stdc++.h>
using namespace std;



int main() {
    int n; cin >> n;
    string s; cin >> s;

    vector<pair<int, int>> queries;

    int q; cin >> q;
    while(q--) {
        char c, d; cin >> c >> d;
        int nc = c-'a', nd = d-'a';
        queries.push_back({nc, nd});
    }

    reverse(queries.begin(), queries.end());

    const int E = 26;
    vector<int> val(E, 0);

    for(int i = 0; i < E; i++) val[i] = i;

    for(auto e : queries) {
        int c = e.first, d = e.second;
        val[c] = val[d];
    }

    for(char c : s) {
        int nc = c-'a';
        nc = val[nc];

        char d = 'a'+nc;
        cout << d;
    }

    cout << "\n";

    return 0;
}
