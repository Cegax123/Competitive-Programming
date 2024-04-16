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

int ex(int a, int b, int c) {
    int ans = 1;
    while(b) {
        if(b&1) ans = ans * 1ll * a % c;
        b >>= 1;
        a = a * 1ll * a % c;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vi d;
    vector<string> t;

    string s; cin >> s;
    d.pb(0); t.pb(s);

    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        string tmp; cin >> tmp;
        d.pb(tmp[0]-'0');
        t.pb(tmp.substr(3, (int) tmp.size()-3));
    }

    const int mod = 1000000007;

    int len[10], val[10];

    for(int i = 0; i < 10; i++) {
        len[i] = 1;
        val[i] = i;
    }

    for(int i = n; i >= 0; i--) {
        int nlen = 0, nval = 0;

        for(char c : t[i]) {
            int dc = c-'0';
            nval = ex(10, len[dc], mod) * 1ll * nval % mod;
            nval = (nval + val[dc]) % mod;

            nlen = (nlen + len[dc]) % (mod-1);
        }

        val[d[i]] = nval;
        len[d[i]] = nlen;
    }

    cout << val[0] << "\n";

    return 0;
}


