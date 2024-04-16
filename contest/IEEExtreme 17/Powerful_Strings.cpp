#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int SUML = 2005;
const int E = 26;

int n;
int nodes = 1;
int suf[SUML];
int term[SUML];
int super[SUML];
int val[SUML];
int go[SUML][E];

void insert(const string& s) {
    int pos = 0;
    for(int i = 0; i < (int) s.size(); i++) {
        int nxt = s[i]-'a';
        if(go[pos][nxt] == 0) {
            go[pos][nxt] = nodes++;
        }
        pos = go[pos][nxt];
    }
    term[pos]++;
}

void build(int src=0) {
    queue<int> Q;
    Q.emplace(src);
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();

        if(term[suf[u]]) super[u] = suf[u];
        else super[u] = super[suf[u]];

        val[u] = term[u] + val[suf[u]];

        for(int c = 0; c < E; c++) {
            if(go[u][c]) {
                int v = go[u][c];
                Q.emplace(v);

                suf[v] = u == 0 ? 0 : go[suf[u]][c];
            }
            else {
                go[u][c] = u == 0 ? 0 : go[suf[u]][c];
            }
        }
    }
}

namespace MatrixMult {

    using u32 = std::uint32_t;
    using u64 = std::uint64_t;

    constexpr u32 MAX_SIZE = 1024;
    constexpr u64 MOD = 998244353ULL;
    constexpr u64 BIG_MOD = MOD * MOD * 9ULL;

    void _matrix_mult(const u32* __restrict__ A, const u32* __restrict__ B,
                      u32* __restrict__ C, const u32 Cn, const u32 Am,
                      const u32 Cm) {
        static u64 buf0 alignas(32)[MAX_SIZE];
        static u64 buf1 alignas(32)[MAX_SIZE];
        static u64 buf2 alignas(32)[MAX_SIZE];
        static u64 buf3 alignas(32)[MAX_SIZE];
        // replacing int by u32 for loops might disallow auto-vectorization
        int j = 0;
        for (; j + 4 <= Cn; j += 4) {
            std::fill(buf0, buf0 + Cm, 0);
            std::fill(buf1, buf1 + Cm, 0);
            std::fill(buf2, buf2 + Cm, 0);
            std::fill(buf3, buf3 + Cm, 0);
            const auto* A_offset0 = A + (j + 0) * Am;
            const auto* A_offset1 = A + (j + 1) * Am;
            const auto* A_offset2 = A + (j + 2) * Am;
            const auto* A_offset3 = A + (j + 3) * Am;
            int k = 0;
            for (; k + 18 <= Am; k += 18) {
                for (int _k = k; _k < k + 18; ++_k) {
                    const u64 a0 = A_offset0[_k];
                    const u64 a1 = A_offset1[_k];
                    const u64 a2 = A_offset2[_k];
                    const u64 a3 = A_offset3[_k];
                    const auto* B_offset = B + _k * Cm;
#pragma GCC ivdep
                    for (int i = 0; i < Cm; ++i) {
                        u64 x = B_offset[i];
                        buf0[i] += a0 * x;
                        buf1[i] += a1 * x;
                        buf2[i] += a2 * x;
                        buf3[i] += a3 * x;
                    }
                }
#pragma GCC ivdep
                for (int i = 0; i < Cm; ++i) {
                    buf0[i] += (buf0[i] >> 47) * ((1ULL << 47) % MOD - (1ULL << 47));
                }
#pragma GCC ivdep
                for (int i = 0; i < Cm; ++i) {
                    buf1[i] += (buf1[i] >> 47) * ((1ULL << 47) % MOD - (1ULL << 47));
                }
#pragma GCC ivdep
                for (int i = 0; i < Cm; ++i) {
                    buf2[i] += (buf2[i] >> 47) * ((1ULL << 47) % MOD - (1ULL << 47));
                }
#pragma GCC ivdep
                for (int i = 0; i < Cm; ++i) {
                    buf3[i] += (buf3[i] >> 47) * ((1ULL << 47) % MOD - (1ULL << 47));
                }
            }
            for (; k < Am; ++k) {
                const u64 a0 = A[(j + 0) * Am + k];
                const u64 a1 = A[(j + 1) * Am + k];
                const u64 a2 = A[(j + 2) * Am + k];
                const u64 a3 = A[(j + 3) * Am + k];
                const u32 offset = k * Cm;
                const auto* B_offset = B + offset;
#pragma GCC ivdep
                for (int i = 0; i < Cm; ++i) {
                    u64 x = B_offset[i];
                    buf0[i] += a0 * x;
                    buf1[i] += a1 * x;
                    buf2[i] += a2 * x;
                    buf3[i] += a3 * x;
                }
            }
            auto* C_offset = C + j * Cm;
#pragma GCC ivdep
            for (int i = 0; i < Cm; ++i) {
                C_offset[i] = buf0[i] % MOD;
            }
            C_offset += Cm;
#pragma GCC ivdep
            for (int i = 0; i < Cm; ++i) {
                C_offset[i] = buf1[i] % MOD;
            }
            C_offset += Cm;
#pragma GCC ivdep
            for (int i = 0; i < Cm; ++i) {
                C_offset[i] = buf2[i] % MOD;
            }
            C_offset += Cm;
#pragma GCC ivdep
            for (int i = 0; i < Cm; ++i) {
                C_offset[i] = buf3[i] % MOD;
            }
        }
        auto* buf = buf0;
        for (; j < Cn; ++j) {
            std::fill(buf, buf + Cm, 0);
            const auto* A_offset = A + j * Am;
            int k = 0;
            for (; k + 18 <= Am; k += 18) {
                for (int _k = k; _k < k + 18; ++_k) {
                    const auto* B_offset = B + _k * Cm;
                    const u64 a = A_offset[_k];
#pragma GCC ivdep
                    for (int i = 0; i < Cm; ++i) {
                        buf[i] += a * B_offset[i];
                    }
                }
                for (int i = 0; i < Cm; ++i) {
                    buf[i] += (buf[i] >> 47) * ((1ULL << 47) % MOD - (1ULL << 47));
                }
            }
            for (; k < Am; ++k) {
                const u64 a = A[j * Am + k];
                const auto* B_offset = B + k * Cm;
#pragma GCC ivdep
                for (int i = 0; i < Cm; ++i) {
                    buf[i] += a * B_offset[i];
                }
            }
            auto* C_offset = C + j * Cm;
            for (int i = 0; i < Cm; ++i) {
                C_offset[i] = buf[i] % MOD;
            }
        }
    }

    template <class T>
    struct Matrix {
       private:
        std::vector<T> a;
        int n, m;

       public:
        Matrix(int n, int m) : n(n), m(m), a(n * m) {}
        T* operator[](const int& i) { return a.data() + i * m; }
        Matrix operator*(Matrix& B) {
            assert(this->m == B.n);
            Matrix<T> C(this->n, B.m);
            _matrix_mult((*this)[0], B[0], C[0], this->n, this->m, B.m);
            return C;
        }
    };

}
//namespace MatrixMult
using MatrixMult::Matrix;
using MatrixMult::u32;

typedef vector<int> vi;
typedef vector<vi> Mat;

const int mod = 998244353;

int main() {
    ll n; cin >> n;
    int m; cin >> m;

    for(int i = 0; i < m; i++) {
        string s; cin >> s;
        insert(s);
    }

    build();

    Matrix<u32> Ap(nodes, nodes), Mp(nodes, nodes);

    for(int i = 0; i < nodes; i++)
        for(int j = 0; j < nodes; j++) {
            Ap[i][j] = 0;
            Mp[i][j] = i == j;
        }

    for(int from = 0; from < nodes; from++) {
        for(int c = 0; c < E; c++) {
            int to = go[from][c];

            int d = 1;

            for(int i = 0; i < val[to]; i++) {
                d = d * 2ll % mod;
            }

            Ap[to][from] += d;
            Ap[to][from] %= mod;
        }
    }

    while(n) {
        if(n&1ll) Mp = Mp * Ap;
        Ap = Ap * Ap;
        //A = mul_mat(A, A);
        n >>= 1;
    }

    Matrix<u32> res(nodes, 1);

    res[0][0] = 1;

    for(int i = 1; i < nodes; i++)
        res[i][0] = 0;

    res = Mp * res;
    ll ans = 0;

    for(int i = 0; i < nodes; i++) {
        ans += res[i][0];
        ans %= mod;
    }

    cout << ans << "\n";

    return 0;
}

