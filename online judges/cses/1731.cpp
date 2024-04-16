#include <bits/stdc++.h>
using namespace std;

const int E = 26;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;

int trie[maxn][E];
bool term[maxn];
int nodes = 1;

void insert(string s) {
    int pos = 0;

    for(char c : s) {
        int nxt = c-'a';

        if(trie[pos][nxt] == 0) {
            trie[pos][nxt] = nodes++;
        }

        pos = trie[pos][nxt];
    }

    term[pos] = 1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s; cin >> s;
    int n = s.size();

    int t; cin >> t;
    while(t--) {
        string p; cin >> p;
        insert(p);
    }

    vector<int> dp(n+1, 0);

    dp[0] = 1;

    for(int i = 0; i < n; i++) {
        int pos = 0;
        int len = 0;
        for(int j = i; j < n; j++) {
            int nxt = s[j] - 'a';
            len++;
            if(trie[pos][nxt] == 0) break;

            pos = trie[pos][nxt];

            if(term[pos] and i + len <= n) dp[i+len] = (dp[i+len] + dp[i]) % mod;
        }
    }

    cout << dp[n] << "\n";
	
    return 0;
}


