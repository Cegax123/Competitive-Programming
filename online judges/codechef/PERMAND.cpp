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
        if(n&(n-1)) {
            cout << "-1\n";
            continue;
        }

        if(n == 1) {
            cout << "1\n1\n";
            continue;
        }

        vector<bool> used(n+1, 0);
        vi a, b;

        for(int i = 1; i <= n; i++) {
            if(used[i]) continue;
            int other = (n-1)^i;
            if(other == 0) other = n;

            a.pb(i);
            a.pb(other);
            b.pb(other);
            b.pb(i);

            used[i] = 1;
            used[other] = 1;
        }

        for(int x : a)
            cout << x << " ";
        cout << "\n";
        for(int x : b)
            cout << x << " ";
        cout << "\n";
    }

	
    return 0;
}


