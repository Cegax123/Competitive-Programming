#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    cin.ignore();

    const int E = 26;

    for(int i = 0; i < n; i++) {
        string s; getline(cin, s);

        cout << s << endl;

        vector<int> cnt(7, 0);

        for(char c : s) {
            if(c >= 'a' and c <= 'g') cnt[c-'a']++;
        }

        vector<pair<int, int>> p;

        for(int i = 0; i < 7; i++) {
            p.push_back({cnt[i], i});
            cout << i << " " << cnt[i] << "\n";
        }
        cout << endl;

        sort(p.begin(), p.end());

        //cout << p[0].second << "\n";
    }

    return 0;
}
