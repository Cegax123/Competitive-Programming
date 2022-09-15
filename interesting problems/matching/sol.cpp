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

const int maxn = 1e6+5;
int prv[maxn], nxt[maxn];

const int e = -1;

bool f(int i, int pos, const vi& t) { 
    if(prv[pos] != -1) {
        if(i < prv[pos] or t[i-prv[pos]] == e or t[i-prv[pos]] > t[i]) 
            return 0;
    }

    if(nxt[pos] != -1) {
        if(i < nxt[pos] or t[i-nxt[pos]] == e or t[i-nxt[pos]] < t[i]) 
            return 0;
    }

    return 1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    memset(prv, -1, sizeof(prv));
    memset(nxt, -1, sizeof(nxt));

	int n, m; cin >> n >> m;

    int h[n], a[m];

    for(int i = 0; i < n; i++) {
        int si; cin >> si;
        si--;

        h[si] = i;
    }

    for(int i = 0; i < m; i++)
        cin >> a[i];

    set<ii> s;

    for(int i = 0; i < n; i++) 
        s.insert({h[i], i});

    for(int i = n-1; i >= 0; i--) {
        auto it = s.find({h[i], i});

        if(it != s.begin()) {
            it--;

            prv[i] = i - it->second;

            it++;
        }

        it++;

        if(it != s.end()) 
            nxt[i] = i - it->second;

        s.erase({h[i], i});
    }

    vi t;

    for(int i = 0; i < n; i++) 
        t.pb(h[i]);

    t.pb(e);

    for(int i = 0; i < m; i++) 
        t.pb(a[i]);

    vi pi(t.size());
    pi[0] = 0;
    
    for(int i = 1; i < (int) t.size(); i++) {
        if(i == n) {
            pi[i] = 0;
            continue;
        }

        int k = pi[i-1];
        
        if(k == n) k = pi[k-1];

        while(k and !f(i, k, t)) 
            k = pi[k-1];

        if(f(i, k, t)) pi[i] = k+1;
        else pi[i] = 0;
    }

    vi ans;

    for(int i = n; i < (int) t.size(); i++) {
        // cout << pi[i] << " ";
        if(pi[i] == n) {
            ans.pb(i - 2 * n + 1);
        }
    }

    cout << ans.size() << "\n";

    for(int x : ans)
        cout << x << " ";
	
    return 0;
}



