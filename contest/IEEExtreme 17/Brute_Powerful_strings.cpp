#include<bits/stdc++.h>
using namespace std;

vector<string> T;
string curr;

void gen(int pos, int n) {
    if(pos == n) {
        T.push_back(curr);
        return;
    }

    for(char c = 'a'; c <= 'z'; c++) {
        curr += c;
        gen(pos+1, n);
        curr.pop_back();
    }
}

int main() {
    int n, m; cin >> n >> m;
    vector<string> s;
    for(int i = 0; i < m; i++) {
        string t; cin >> t;
        s.push_back(t);
    }

    int ans = 0;

    const int mod = 998244353;

    gen(0, n);

    for(const string& t : T) {
        int cnt = 0;
        for(const string& p : s) {
            int k = p.size();
            for(int i = 0; i + k - 1 < (int) t.size(); i++) {
                if(t.substr(i, k) == p) cnt++;
            }
        }

        int d = 1;
        for(int i = 0; i < cnt; i++) {
            d = d * 2ll % mod;
        }

        ans += d;
        ans %= mod;
    }

    cout << ans << "\n";


    return 0;
}
