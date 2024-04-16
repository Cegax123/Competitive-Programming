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
    vii queries;

    for(int i = 1; i <= t; i++) {
        int n; cin >> n;
        queries.pb({n, i});
    }

    sort(all(queries));

    double curr = 0.0;
    int n = 1;

    double ans[t+1];

    for(int i = 0; i < t; i++) {
        while(n <= queries[i].first) {
            curr += 1.0 / n;
            n++;
        }

        ans[queries[i].second] = curr;
    }

    for(int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";

        cout << setprecision(12) << fixed;
        cout << ans[i] << "\n";
    }
	
    return 0;
}

