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

vector<int> z_function(const vi& s) {
    int n = (int) s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        string sigma, w, s; cin >> sigma >> w >> s;

        map<char, int> pos;
        for(int i = 0; i < (int) sigma.size(); i++) 
            pos[sigma[i]] = i;

        auto get_d = [&](int a, int b) {
            int d = b-a;
            if(d < 0) d += sigma.size();
            return d;
        };

        vi ans;

        if(w.size() == 1) {
            int cnt[sigma.size()];
            memset(cnt, 0, sizeof(cnt));

            for(char c : s) cnt[pos[c]]++;

            for(int i = 0; i < (int) sigma.size(); i++) {
                if(cnt[i] == 1) {
                    ans.pb(get_d(pos[w[0]], i));
                }
            }
        }
        else {
            vi diffw, diffs;

            auto calc_diff = [&](const string& a, vi& diffa) {
                for(int i = 1; i < (int) a.size(); i++) {
                    int d = get_d(pos[a[i-1]], pos[a[i]]);
                    diffa.pb(d);
                }
            };

            calc_diff(w, diffw);
            calc_diff(s, diffs);

            vi tot;

            for(int x : diffw) tot.pb(x);
            tot.pb(-1);
            for(int x : diffs) tot.pb(x);

            vi z = z_function(tot);

            int cnt[sigma.size()];
            memset(cnt, 0, sizeof(cnt));

            for(int i = w.size(); i < (int) tot.size(); i++) {
                if(z[i] >= (int) w.size()-1) {
                    cnt[pos[s[i-w.size()]]]++;
                }
            }

            for(int i = 0; i < (int) sigma.size(); i++) {
                if(cnt[i] == 1) {
                    int d = get_d(pos[w[0]], i);
                    ans.pb(d);
                }
            }
        }

        sort(all(ans));

        if(ans.empty()) cout << "no solution";
        else if((int) ans.size() == 1) cout << "unique: ";
        else cout << "ambiguous: ";

        for(int x : ans) cout << x << " ";
        cout << "\n";
    }

	
    return 0;
}


