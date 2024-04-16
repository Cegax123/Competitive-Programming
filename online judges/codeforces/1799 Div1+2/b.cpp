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
        int a[n];
        set<ii> b;

        int cnt1 = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            b.insert({a[i], i+1});
            cnt1 += a[i] == 1;
        }

        if(cnt1 > 0) {
            if(cnt1 == n) cout << "0\n";
            else cout << "-1\n";
            continue;
        }
        
        vii op;

        while(true) {
            auto s = *(b.begin());
            auto e = *(b.rbegin());

            if(s.first == e.first) break;

            b.erase(e);

            e.first = (e.first + s.first - 1) / s.first;
            op.pb({e.second, s.second});

            b.insert(e);
        }

        cout << op.size() << "\n";

        for(auto e : op) {
            cout << e.first << " " << e.second << "\n";
        }
    }

	
    return 0;
}


