#include <bits/stdc++.h>
using namespace std;

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
long long random(long long l, long long r) {
    return uniform_int_distribution(l, r)(rng);
}

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

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

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s, t; 
    getline(cin, s);
    getline(cin, t);
    int n; cin >> n;

    gen();

    for(int i = 0; i < k; i++) {
        h[i][0] = s[0];

        for(int j = 1; j < (int) s.size(); j++) {
            h[i][j] = (h[i][j-1] * 1ll * b[i] % mod + (int) (s[j])) % mod;
        }
    }

    auto get_hash = [&](int l, int r) {
        vector<int> H(k, 0);

        for(int i = 0; i < k; i++) {
            H[i] = (h[i][r] - (l == 0 ? 0 : h[i][l-1] * 1ll * pb[i][r-l+1] % mod)) % mod;
            if(H[i] < 0) H[i] += mod;
        }

        return H[0] * 1ll * mod + H[1];
    };

    auto cmp = [&](int len) {
        vector<int> p(k, 0);

        for(int i = 0; i < k; i++) {
            for(int j = 0; j < len; j++) {
                p[i] = (p[i] * 1ll * b[i] % mod + (t[j])) % mod;
            }
        }

        long long P = p[0] * 1ll * mod + p[1];
        //cout << P << endl;

        int cnt = 0;
        for(int i = 0; i + len - 1 < (int) s.size(); i++) {
            //cout << get_hash(i, i+len-1) << endl;
            if(get_hash(i, i+len-1) == P) cnt++;
        }

        return cnt >= n;
    };

    //cout << cmp(4) << endl;

    int l = 1, r = (int) t.size();

    while(l < r) {
        int m = (l+r+1) >> 1;
        if(cmp(m)) l = m;
        else r = m-1;
    }

    if(cmp(l)) cout << t.substr(0, l) << "\n";
    else cout << "IMPOSSIBLE\n";
	
    return 0;
}


