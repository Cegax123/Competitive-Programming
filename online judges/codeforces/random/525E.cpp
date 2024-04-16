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

const int maxv = 18;
map<ll, int> mp[2][15];
ll f[maxv+1];

void process(vector<int>& v, int id) {
    int n = v.size();

    for(int i = 1; i < (1 << n); i++) {
        ll sum = 0;
        for(int k = 0; k < n; k++) {
            if((i>>k)&1) {
                sum += v[k];
            }
        }

        mp[id][0][sum]++;

        for(int j = i; j > 0; j = (j-1)&i) {
            bool cmp = 1;
            ll sum = 0;
            for(int k = 0; k < n; k++) {
                if((i>>k)&1) {
                    if((j>>k)&1) {
                        if(v[k] > 18) {
                            cmp = 0;
                            break;
                        }
                        else {
                            sum += f[v[k]];
                        }
                    }
                    else sum += v[k];
                }
            }

            if(cmp == 0) continue;

            int k = __builtin_popcount(j);
            mp[id][k][sum]++;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    f[0] = 1ll;
    for(int i = 1; i <= maxv; i++) {
        f[i] = f[i-1] * 1ll * i;
    }

    int n, k; cin >> n >> k;
    ll s; cin >> s;
    vector<int> v1, v2;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        if(i < n/2) v1.push_back(a);
        else v2.push_back(a);
    }

    process(v1, 0);
    process(v2, 1);

    ll ans = 0;

    for(int i = 0; i <= min(14, k); i++) {
        for(auto e : mp[0][i]) {
            if(e.first == s) {
                ans += e.second;
            }
        }
    }

    for(int i = 0; i <= min(14, k); i++) {
        for(auto e : mp[1][i]) {
            if(e.first == s) {
                ans += e.second;
            }
        }
    }

    for(int i = 0; i <= min(14, k); i++) {
        for(auto e : mp[0][i]) {
            ll s1 = e.first;

            if(s1 == 0 or s1 == s) continue;
            for(int j = 0; j <= k-i; j++) {
                if(j >= 15) continue;
                ans += e.second * 1ll * mp[1][j][s-s1];
            }
        }
    }

    cout << ans << "\n";
	
    return 0;
}


