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
        int x; cin >> x;

        int a[n], b[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        vi ind(n);
        iota(all(ind), 0);

        sort(all(ind), [&](int x, int y) {
                return a[x] < a[y];
                });

        reverse(all(ind));

        sort(b, b+n);

        int nb[n];
        for(int i = 0; i < x; i++) {
            nb[ind[i]] = b[x-1-i];
        }

        for(int i = x; i < n; i++) {
            nb[ind[i]] = b[n-1-i+x];
        }

        int cnt = 0;

        for(int i = 0; i < n; i++)
            if(a[i] > nb[i]) cnt++;


        if(cnt == x) {
            cout << "YES\n";
            for(int i = 0; i < n; i++) cout << nb[i] << " ";
            cout << "\n";
        }
        else {
            cout << "NO\n";
        }
    }

	
    return 0;
}


