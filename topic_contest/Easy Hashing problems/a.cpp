#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
long long random(long long l, long long r){
   return uniform_int_distribution<long long>(l,r)(rng);
}

const int maxn = 6e5 + 5;

int b[2];
int pb[2][maxn];

void gen() {
    for(int i = 0; i < 2; i++) {
        b[i] = random(0, mod-1);

        pb[i][0] = 1;

        for(int j = 1; j < maxn; j++)
            pb[i][j] = pb[i][j-1] * 1ll * b[i] % mod;
    }
}

const int E = 26;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    gen();

    int n, m; cin >> n >> m;
    set<long long> hh;
    
    for(int tt = 0; tt < n; tt++) {
        string s; cin >> s;
        int k = s.size();

        int H[2];

        for(int i = 0; i < 2; i++) {
            H[i] = 0;

            for(int j = 0; j < k; j++) {
                int c = s[j] - 'a' + 1;
                H[i] = (H[i] + c * 1ll * pb[i][j] % mod) % mod;
            }
        }

        hh.insert({H[0] * 1ll * mod + H[1]});
    }

    for(int i = 0; i < m; i++) {
        string s; cin >> s;
        
        int k = s.size();

        vector<vector<int>> h(2, vector<int>(k));
        vector<int> H(2, 0);
        vector<vector<int>> r(2, vector<int>(k));

        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < k; j++) {
                int c = s[j]-'a'+1;
                h[i][j] = pb[i][j] * 1ll * c % mod;
                H[i] = (H[i] + h[i][j]) % mod;
            }

            for(int j = 0; j < k; j++) {
                r[i][j] = (H[i] - h[i][j]) % mod;
                if(r[i][j] < 0) r[i][j] += mod;
            }
        }

        bool cmp = false;
        for(int j = 0; j < k; j++) {
            for(char d = 'a'; d <= 'z'; d++) {
                if(d == s[j]) continue;
                int c = d-'a'+1;

                int curr1 = (r[0][j] + c * 1ll * pb[0][j] % mod) % mod;
                int curr2 = (r[1][j] + c * 1ll * pb[1][j] % mod) % mod;

                if(hh.count(curr1 * 1ll * mod + curr2)) cmp = true;
            }
        }

        cout << (cmp ? "YES\n" : "NO\n");
    }
    
	
    return 0;
}


