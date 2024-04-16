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
vi a(maxn), b(maxn);
int r[2 * maxn];


mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

long long random(long long l, long long r){
    return uniform_int_distribution<long long>(l,r)(rng);
}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n; cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<int> c;

    for(int i = 0; i < n; i++) {
        c.pb(a[i]);
        c.pb(b[i]);
    }

    sort(all(c));
    c.erase(unique(all(c)), c.end());

    map<int, int> mp;

    for(int i = 0; i < (int) c.size(); i++) {
        mp[c[i]] = i+1;
    }

    for(int i = 0; i < n; i++)
        a[i] = mp[a[i]];

    for(int i = 0; i < n; i++)
        b[i] = mp[b[i]];

    for(int i = 1; i <= 2 * n; i++) {
        r[i] = random(0, 1e9);
    }

    auto process = [&](const vi& v) {
        vector<bool> used(2 * maxn, 0);
        int curr = 0;

        vi ans;

        for(int i = 0; i < n; i++) {
            if(!used[v[i]]) curr ^= r[v[i]];
            used[v[i]] = 1;
            ans.pb(curr);
        }

        return ans;
    };

    vi va = process(a), vb = process(b);

    int q; cin >> q;
    while(q--) {
        int x, y; cin >> x >> y;
        x--; y--;
        cout << (va[x] == vb[y] ? "Yes\n" : "No\n");
    }
	
    return 0;
}


