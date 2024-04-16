#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
long long random(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

const int k = 2;
int b[k];
int pb[k][maxn];

void gen() {
    for(int i = 0; i < k; i++) {
        b[i] = random(0, mod-1);
        pb[i][0] = 1;

        for(int j = 1; j < maxn; j++) {
            pb[i][j] = pb[i][j-1] * 1ll * b[i] % mod;
        }
    }
}

int h[k][maxn];
vector<pair<string, int>> queries[maxn];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    gen();

    int n, m; cin >> n >> m;
    string s; cin >> s;
    
    for(int i = 0; i < k; i++) {
        h[i][0] = s[0]-'a'+1;

        for(int j = 1; j < n; j++) {
            h[i][j] = (h[i][j-1] * 1ll * b[i] % mod + s[j]-'a'+1) % mod;
        }
    }

    auto get_hash = [&](int l, int r) {
        int H[k];
        for(int i = 0; i < k; i++) {
            int curr = h[i][r] - (l == 0 ? 0 : h[i][l-1] * 1ll * pb[i][r-l+1] % mod);
            curr %= mod;

            if(curr < 0) curr += mod;
            H[i] = curr;
        }

        return H[0] * 1ll * mod + H[1];
    };


    for(int i = 0; i < m; i++) {
        string t; cin >> t;
        
        queries[t.size()].push_back({t, i});
    }

    int solved[m];

    for(int i = 1; i < maxn; i++) {
        if(queries[i].empty()) continue;

        vector<int> a;
        map<long long, int> id;
        int curr = 1;
        for(int j = 0; j + i - 1 < n; j++) {
            long long H = get_hash(j, j+i-1);
            if(id[H] == 0) id[H] = curr++;
            a.push_back(id[H]);
        }

        vector<int> last(curr+1, -1e9);
        vector<int> ans(curr+1, 0);

        for(int j = 0; j < (int) a.size(); j++) {
            //if(i == 3) cout << a[j] << " " << last[a[j]] << endl;

            if(j-last[a[j]] >= i) {
                last[a[j]] = j;
                ans[a[j]]++;
            }
        }

        for(auto e : queries[i]) {
            string t = e.first;

            int H[2] = {0, 0};

            for(int tt = 0; tt < 2; tt++) {
                for(int j = 0; j < i; j++) {
                    H[tt] = (H[tt] * 1ll * b[tt] % mod + t[j]-'a'+1) % mod;
                }
            }

            long long HH = H[0] * 1ll * mod + H[1];

            if(id[HH] == 0) {
                solved[e.second] = 0;
            }
            else {
                solved[e.second] = ans[id[HH]];
            }
        }
    }

    for(int i = 0; i < m; i++) {
        cout << solved[i] << "\n";
    }
	
    return 0;
}


