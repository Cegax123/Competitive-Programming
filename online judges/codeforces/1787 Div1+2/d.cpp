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

const int maxn = 2e5 + 5;

int c[maxn], a[maxn], dp[maxn];
int n;

int go(int v) {
    if(c[v] == 2) return dp[v];

    c[v] = 1;

    int nxt = v + a[v];
    
    if(nxt < 0 or nxt >= n) {
        c[v] = 2;
        return dp[v] = -1;
    }

    if(c[nxt] == 0) {
        go(nxt);
        c[v] = 2;
        dp[v] = dp[nxt];
        return dp[v];
    }

    else if(c[nxt] == 1) {
        c[v] = 2;
        return dp[v] = -2;
    }

    else {
        c[v] = 2;
        return dp[v] = dp[nxt];
    }

}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n;

        for(int i = 0; i < n; i++) {
            c[i] = 0;
            dp[i] = 0;
        }

        for(int i = 0; i < n; i++) 
            cin >> a[i];

        vi d;
        d.pb(0);

        c[0] = 2;
        dp[0] = 0;

        bool term = false;


        while(true) {
            int nv = d.back() + a[d.back()];
            if(nv < 0 or nv >= n) {
                term = true;
                break;
            }
            else if(c[nv]) {
                break;
            }
            else {
                d.pb(nv);
                c[nv] = 2;
                dp[nv] = nv;
            }
        }

        ll ans = 0;

        if(term) {
            vi cnt(n, 0);
            int tot = 0;

            for(int i = 0; i < n; i++) {
                if(dp[i] != i) ans += 2*n+1;
                if(go(i) >= -1 and go(i) < n) {
                    tot++;
                    if(go(i) >= 0) cnt[go(i)]++;
                }
            }

            for(int x : d) {
                tot -= cnt[x];
                ans += tot + n + 1;
            }
        }
        else {
            int tot = 0;

            for(int i = 0; i < n; i++)
                if(go(i) == -1) tot++;

            for(int x : d) {
                ans += tot + n + 1;
            }
        }

        cout << ans << "\n";

        //cout << "term: " << term << endl;

        //for(int i = 0; i < n; i++){ 
            //cout << go(i) << " ";
        //}
        
        //cout << endl;
    }

	
    return 0;
}


