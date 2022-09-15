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

const int maxn = 1e6;
const int E = 6;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    int a[n];

    vi cnt(maxn+1, 0);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
	
    vi ans(maxn+1, 0);

    ans[0] = cnt[0];

    int p[E];
    p[0] = 1;

    for(int i = 1; i < E; i++)
        p[i] = p[i-1] * 10;

    for(int i = 1; i <= maxn; i++) {
        int mask = 0;
        int tmp = i;

        for(int j = 0; j < E; j++) {
            if(tmp%10) mask |= (1 << j);
            tmp /= 10;
        }

        ans[i] = cnt[i];

        // cout << i << ": ";

        for(int j = 1; j < (1 << E); j++) {
            if((mask|j) == mask) {
                tmp = i;
                int cnt = 0;

                for(int k = 0; k < E; k++) {
                    if((j >> k)&1) {
                        tmp -= p[k];
                        cnt++;
                    }
                }

                // cout << tmp << " ";

                if(cnt&1) ans[i] += ans[tmp];
                else ans[i] -= ans[tmp];
            }
        }

        // cout << "\n";
    }

    ll res = 0;
    
    for(int i = 0; i < n; i++) {
        int comp = 0;
        bool repeat = 1;
        
        for(int j = 0; j < E; j++) {
            int d = (a[i]/p[j])%10;
            comp += (9-d) * p[j];

            if(d >= 5) repeat = 0;
        }

        res += (ll) ans[comp]-repeat;
    }

    cout << (res >> 1) << "\n";
	
	return 0;
}

