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
        ll k; cin >> k;
        int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
        if(l1 > l2) {
            swap(l1, l2);
            swap(r1, r2);
        }
        
        ll diff = max(0, l2-r1);
        ll c1;
        ll def;

        if(r1 < l2) {
            c1 = diff + (r2-l2) + (r1-l1);
            def = 0;
        }
        else {
            c1 = abs(l2-l1) + abs(r2-r1);
            def = min(r2, r1) - max(l2, l1);
        }

        ll global = -1;
        ll t_k = k;
        
        for(int i = 1; i <= n; i++) {
            ll cost = diff * i;

            k = t_k;
            k = max(0ll, k - def * i);

            cost += min(c1 * i, k);
            k = max(0ll, k - c1 * i);

            cost += 2 * k;

            if(global == -1) global = cost;
            global = min(global, cost);
        }

        cout << global << "\n";

    }

	
    return 0;
}


