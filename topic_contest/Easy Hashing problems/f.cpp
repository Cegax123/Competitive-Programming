#include <bits/stdc++.h>
using namespace std;

const long long N = 1e8;

bool is_prime(long long x) {
    if(x <= 1) return false;

    for(int i = 2; i * 1ll * i <= x; i++)
        if(x % i == 0) return false;

    return true;
}

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
long long random(long long l, long long r){
   return uniform_int_distribution<long long>(l,r)(rng);
}

long long gen_prime() {
    long long num = random(N, 2 * N - 1);

    while(!is_prime(num)) num++;

    return num;
}

const int maxn = 1e6 + 5;
const int b = 10;
const int k = 2;

int mod[k];
int h[k][maxn];
int pb[k][maxn];
int ib[k][maxn];

int ex(int a, int b, int c) {
    int ans = 1;
    while(b) {
        if(b&1) ans = ans * 1ll * a % c;
        a = a * 1ll * a % c;
        b >>= 1;
    }

    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    for(int i = 0; i < k; i++) {
        mod[i] = gen_prime();
        ib[i][0] = 1;
        ib[i][1] = ex(b, mod[i]-2, mod[i]);

        for(int j = 2; j < maxn; j++) {
            ib[i][j] = ib[i][j-1] * 1ll * ib[i][1] % mod[i];
        }

        pb[i][0] = 1;
        for(int j = 1; j < maxn; j++) {
            pb[i][j] = pb[i][j-1] * 1ll * b % mod[i];
        }
    }


    string s; cin >> s;
    int n = s.size();

    for(int i = 0; i < k; i++) {
        h[i][0] = s[0]-'0';
        for(int j = 1; j < n; j++) {
            h[i][j] = (h[i][j-1] * 1ll * b % mod[i] + (s[j]-'0')) % mod[i];
        }
    }

    auto get_hash = [&](int l, int r, int id) {
        int H = h[id][r] - (l == 0 ? 0 : h[id][l-1] * 1ll * pb[id][r-l+1] % mod[id]);
        H %= mod[id];
        if(H < 0) H += mod[id];
        return H;
    };

    auto comp = [&](int L, int M, int R) {
        if(s[0] == '0' and L > 1) return false;
        if(s[L] == '0' and M > 1) return false;
        if(s[L+M] == '0' and R > 1) return false;

        for(int id = 0; id < k; id++) {
            int hL = get_hash(0, L-1, id);
            int hM = get_hash(L, L+M-1, id);
            int hR = get_hash(L+M, n-1, id);

            int sum = (hL+hM) % mod[id];
            if(sum != hR) return false;
        }
        return true;
    };

    vector<int> ans(3, 0);
    for(int r = 1; r <= n-2; r++) {
        int R = r;
        int L = r, M = n - r - L;

        if(M >= 1) {
            if(comp(L, M, R)) {
                ans[0] = L;
                ans[1] = M;
                ans[2] = R;
            }
        }
        
        L = r-1, M = n-r-L;

        if(M >= 1) {
            if(comp(L, M, R)) {
                ans[0] = L;
                ans[1] = M;
                ans[2] = R;
            }
        }

        M = r, L = n-r-M;

        if(L >= 1) {
            if(comp(L, M, R)) {
                ans[0] = L;
                ans[1] = M;
                ans[2] = R;
            }
        }

        M = r-1, L = n-r-M;

        if(L >= 1) {
            if(comp(L, M, R)) {
                ans[0] = L;
                ans[1] = M;
                ans[2] = R;
            }
        }
    }

    cout << s.substr(0, ans[0]) << "+" << s.substr(ans[0], ans[1]) << "=" << s.substr(ans[0] + ans[1], ans[2]) << "\n";
	
    return 0;
}


