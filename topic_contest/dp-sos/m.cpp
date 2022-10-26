// SOLVED

#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define rall(A) A.rbegin(),A.rend()
#define pb push_back 
#define dbg(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
//cout << setprecision(12) << fixed;

const int D = 6;
const int LMT = 1e6;
const int mod = 1e9+7;

int p10[D];
ll p2[LMT+1];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    p10[0] = 1;
    for(int i = 1; i < D; i++)
        p10[i] = p10[i-1] * 10;

    p2[0] = 1;
    for(int i = 1; i <= LMT; i++)
        p2[i] = (p2[i-1] * 2) % mod;

    vector<ll> cnt(LMT, 0), sum(LMT, 0), sum2(LMT, 0);

    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        ll a; cin >> a;
        cnt[a]++;
        sum[a] = (sum[a] + a) % mod;
        sum2[a] = (sum2[a] + a * a) % mod;
    }

    for(int i = 0; i < D; i++) {
        for(int num = 0; num < LMT; num++) {

            int dgt = (num / p10[i]) % 10;
            int new_num = num + p10[i];

            for(int j = dgt+1; j <= 9; j++) {
                cnt[num] += cnt[new_num];
                sum[num] = (sum[num] + sum[new_num]) % mod;
                sum2[num] = (sum2[num] + sum2[new_num]) % mod;

                new_num += p10[i];
            }
        }
    }

    vector<ll> p(LMT);

    for(int i = 0; i < LMT; i++) {
        if(cnt[i] == 0) p[i] = 0;
        else if(cnt[i] == 1) p[i] = sum2[i];
        else {
            p[i] = (sum[i] * sum[i] + sum2[i]) % mod;
            p[i] = (p2[cnt[i]-2] * p[i]) % mod;
        }

        assert(p[i] >= 0);
    }

    vector<ll> G(LMT, 0);

    for(int i = 0; i < LMT; i++) {
        for(int j = 0; j < (1 << D); j++) {
            bool cmp = 1;
            int nxt = i;
            int cnt_1 = 0;

            for(int k = 0; k < D; k++) {
                if(((j >> k)&1) == 0) continue;
                int dgt = (i / p10[k]) % 10;

                if(dgt == 9) cmp = 0;
                nxt += p10[k];

                cnt_1++;
            }

            if(cmp == 0) continue;

            if(cnt_1&1) G[i] -= p[nxt];
            else G[i] += p[nxt];
        }

        G[i] %= mod;
        if(G[i] < 0) G[i] += mod;

        assert(G[i] >= 0);
    }

    ll ans = 0;
    for(int i = 0; i < LMT; i++) {
        G[i] = G[i] * i;

        ans ^= G[i];
    }

    cout << ans << "\n";
	
	return 0;
}

