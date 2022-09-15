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

struct BIT {
    vector<int> bit;  // binary indexed tree
    int n;

    BIT(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    BIT(vector<int> a) : BIT(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

const int E = 26;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    string s; cin >> s;
    int n = s.size();

    vi pos[E];

    for(int i = 0; i < n; i++) 
        pos[s[i]-'a'].pb(i);
    
    vii pairs;
    int cnt_odd = 0;

    for(int i = 0; i < E; i++) {
        if(pos[i].size()&1) cnt_odd++;

        int k = pos[i].size();
        for(int j = 0; j < k; j++) {
            if(pos[i][j] <= pos[i][k-1-j]) {
                pairs.pb({pos[i][j], pos[i][k-1-j]});
            }
        }
    }

    if(cnt_odd >= 2) {
        cout << "-1\n";
        return 0;
    }

    int a[n];

    sort(all(pairs));

    int ind = 0;

    for(int i = 0; i < (int) pairs.size(); i++) {
        if(pairs[i].first == pairs[i].second) {
            a[pairs[i].first] = n/2;
            continue;
        }

        a[pairs[i].first] = ind;
        a[pairs[i].second] = n-1-ind;

        ind++;
    }

    BIT ft(n+1);
    ll ans = 0;

    for(int i = 0; i < n; i++) {
        ans += (ll) ft.sum(a[i]+1, n);
        ft.add(a[i], 1);
    }
    
    // for(int i = 0; i < n; i++)
    //     cout << a[i] << " ";
    //
    // cout << "\n";

    cout << ans << "\n";
	
    return 0;
}


