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



int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vi a;

        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            if(x) a.pb(x);
        }

        n = a.size();

        set<pair<ll, ll>> s, q;
        int ind = 0;
        int k = 0;
        while(ind < n) {
            ll sum = 0;
            int sign = (a[ind] > 0 ? 1 : -1);

            while(ind < n and a[ind] * sign > 0) {
                sum += a[ind];
                ind++;
            }

            s.insert({abs(sum), k});
            q.insert({k, abs(sum)});

            k++;
        }
        
        ll curr = 0;

        while(!s.empty()) {
            auto u = *s.begin(); s.erase(u);

            //cout << u.first << " " << curr << endl;

            curr = u.first;
            auto it = q.find({u.second, u.first});

            if(it != q.begin() and next(it) != q.end()) {
                auto l = *prev(it), r = *next(it);
                s.erase({l.second, l.first});
                s.erase({r.second, r.first});

                q.erase(l);
                q.erase(r);

                s.insert({l.second + r.second - curr, l.first});
                q.insert({l.first, l.second + r.second - curr});
            }

            q.erase(it);
        }

        cout << curr << "\n";
    }

	
    return 0;
}


