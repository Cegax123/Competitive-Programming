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
        vi a(n), b(n);

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        sort(all(a)); sort(all(b));

        vi diff;

        for(int i = 0; i < n; i++) {
            if(a[n-1] > b[n-1]) {
                diff.pb(b[i]-a[n-1]);
                diff.pb(b[i]-(-a[n-1]));
            }
            else {
                diff.pb(b[n-1]-a[i]);
                diff.pb(b[n-1]-(-a[i]));
            }
        }

        int p[2];
        int h[n];

        bool found = 0;

        for(int z : diff) {
            multiset<int> c;
            multiset<int> d;

            vi q, t;

            for(int i = 0; i < n; i++) {
                c.insert(a[i]);
                d.insert(b[i]);
            }

            bool comp = 1;
            for(int i = 0; i < n; i++) {
                int x = *c.rbegin(), y = *d.rbegin();

                if(x > y) {
                    if(d.find(abs(x + z)) != d.end()) {
                        c.erase(c.find(x));
                        d.erase(d.find(abs(x+z)));
                        
                        q.pb(x);
                        t.pb(x+z);
                    }
                    else if(d.find(abs(-x+z)) != d.end()) {
                        c.erase(c.find(x));
                        d.erase(d.find(abs(-x+z)));

                        q.pb(-x);
                        t.pb(-x+z);
                    }
                    else {
                        comp = 0;
                    }
                }
                else {
                    if(c.find(abs(y-z)) != c.end()) {
                        d.erase(d.find(y));
                        c.erase(c.find(abs(y-z)));

                        t.pb(y);
                        q.pb(y-z);
                    }
                    else if(c.find(abs(-y-z)) != c.end()) {
                        d.erase(d.find(y));
                        c.erase(c.find(abs(-y-z)));

                        t.pb(-y);
                        q.pb(-y-z);
                    }
                    else {
                        comp = 0;
                    }
                }

                if(!comp) break;
            }

            if(comp) {
                int x = *min_element(all(q)), y = *min_element(all(t));

                p[0] = 0, p[1] = 0;

                if(x < 0) p[0] = -x;
                if(y < 0) p[1] = -y;

                if(q[0] + p[0] < t[0] + p[1]) {
                    p[0] += t[0] + p[1] - q[0] - p[0];
                }
                else {
                    p[1] += q[0] + p[0] - t[0] - p[1];
                }

                for(int i = 0; i < n; i++) {
                    h[i] = q[i] + p[0];
                }

                found = 1;
                break;
            }
        }
        
        if(!found) cout << "NO\n";
        else {
            cout << "YES\n";
            for(int i = 0; i < n; i++) cout << h[i] << " ";
            cout << "\n";
            cout << p[0] << " " << p[1] << "\n";
        }
    }

	
    return 0;
}


